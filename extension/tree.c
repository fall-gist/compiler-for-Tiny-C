#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include "tree.h"
#include "compiler.tab.h"

int semnerrs;
token symtab;
int last_alloc = 0;
int top_alloc = 0;

tree make_tuple(int opr, tree n0, tree n1, tree n2, tree n3){
	tree t = (tree)malloc(sizeof(union nd));
	t->tp.op = opr;
	t->tp.a[0] = n0;
	t->tp.a[1] = n1;
	t->tp.a[2] = n2;
	t->tp.a[3] = n3;
	return t;   
}

tree make_tuple1(int op, tree n0){
	return make_tuple(op, n0, NULL, NULL, NULL);
}

tree make_tuple2(int op, tree n0, tree n1){
	return make_tuple(op, n0, n1, NULL, NULL);
}

tree make_tuple3(int op, tree n0, tree n1, tree n2){
	return make_tuple(op, n0, n1, n2, NULL);
}

tree make_token_node(char *str){
	tree t = (tree)malloc(sizeof(union nd));
	t->tk.next = symtab;
	symtab = &(t->tk);
	t->tk.op = IDENTIFIER;
	t->tk.name = strdup(str);
	t->tk.lev = cur_lev;
	return t;
}

tree make_constant_node(int i){
	tree t = (tree)malloc(sizeof(union nd));
	t->c.op = CONST;
	t->c.v = i;
	return t;
}

tree make_decl(tree n){
	switch(n->tk.kind){
		case VAR:
			if(n->tk.lev == cur_lev)
				error("redeclaration of '%s'", n->tk.name);
			n = make_token_node(n->tk.name);
			break;
		case FUN:
		case UNDEFFUN:
			if(n->tk.lev == cur_lev)
				error("'%s' redeclared as different kind of symbol", n->tk.name);
			n = make_token_node(n->tk.name);
			break;
		case PARM:
			warn("declaration of '%s' shadows a parameter", n->tk.name);
			n = make_token_node(n->tk.name);
			break;
		case FRESH:
			break;
	}
	n->tk.kind = VAR;
	return n;
}

tree make_parm_decl(tree n){
	switch(n->tk.kind){
		case VAR:
		case FUN:
		case UNDEFFUN:
			n = make_token_node(n->tk.name);
			break;
		case PARM:
			error("redeclaration of '%s'", n->tk.name);
			return n;
		case FRESH:
			break;
	}
	n->tk.kind = PARM;
	return n;
}

tree make_fun_def(tree n){
	switch(n->tk.kind){
		case VAR:
			error("'%s' redeclared as different kind of symbol", n->tk.name);
			break;
		case FUN:
			error("redefinition of '%s'", n->tk.name);
			break;
		case UNDEFFUN:
		case FRESH:
			n->tk.kind = FUN;
			break;
	}
	return n;
}

tree ref_var(tree n){
	switch(n->tk.kind){
		case VAR:
		case PARM:
			break;
		case FUN:
		case UNDEFFUN:
			error("function '%s' is used as variable", n->tk.name);
			break;
		case FRESH:
			error("'%s' undeclared variable", n->tk.name);
			n->tk.kind = VAR;  /* エラーリカバリ用の処理 */
			break;
	}
	return n;
}

tree ref_fun(tree n){
	switch(n->tk.kind){
		case VAR:
		case PARM:
			error("variable '%s' is used as function", n->tk.name);
			break;
		case FUN:
		case UNDEFFUN:
			break;
		case FRESH:
			warn("'%s' undeclared function", n->tk.name);
			n->tk.kind = UNDEFFUN;
			if(n->tk.lev > 0) globalize_sym(n);
			break;
	}
	return n;
}

tree lookup_sym(char *c){
	token tmp = symtab;
	while(tmp != NULL){
		if(!(strcmp(c, tmp->name)))
			 return (tree)tmp;
		else
			 tmp = tmp->next;
	}
   return NULL;
}

void globalize_sym(tree n){
	token now = symtab, prev = NULL;
	while(now->next != NULL){
		if(now == &(n->tk)){
			if(prev != NULL){
				prev->next = now->next;
				now->next = NULL;
				now = prev->next;
			// スタックのトップにある場合
			}else{
				prev = now->next;
				now->next = NULL;
				now = prev;
				prev = NULL;
				symtab = now;
			}
		}else{
			prev = now;
			now = prev->next;
		}
	}
	now->next = &(n->tk);
	n->tk.lev = 0;
}

void pop(int c_lev){
	while(symtab != NULL){
		if(symtab->lev == c_lev)
			symtab = symtab->next;
		else break;
	}
}

void error(char *fmt, ...){
	va_list argp;
	va_start(argp, fmt);
	semnerrs++;
	fprintf(stderr, "%d: ", yylineno);
	vfprintf(stderr, fmt, argp);
	fprintf(stderr, "\n");
	va_end(argp);
}

void warn(char *fmt, ...){
	va_list argp;
	va_start(argp, fmt);
	fprintf(stderr, "%d: warning: ", yylineno);
	vfprintf(stderr, fmt, argp);
	fprintf(stderr, "\n");
	va_end(argp);
}

void set_offset(tree n){
	if(n == NULL) return;
	switch(n->tk.kind){
		case PARM:
			n->tk.offset = 4+4*number_of_param;
			break;
		case FUN:
			n->tk.offset = number_of_param;
			break;
	}
}

void chkarg(tree n){
	tree fun_tree = n->tp.a[0];
	token fun = &fun_tree->tk;
	tree args = n->tp.a[1];
	int num = 0;
	
	if(args != NULL){
		while(args->tp.op == ARGUEXPRL){
			num++;
			args = args->tp.a[0];	
		}
		num++;
	}
	if(fun->kind == UNDEFFUN)
		fun->offset = num;
	else if(fun->offset != num)
		error("%d argument(s) expected but %d passed", n->tk.offset, num);
}

int allocate_loc(){
	last_alloc -= 4;
	if(last_alloc < top_alloc)
		top_alloc = last_alloc;
	return last_alloc;
}

void release_loc(){
	last_alloc += 4;
}

void check_break(){
	if(!in_loop){
		error("error: break statement not within loop");
	}
}

void check_continue(){
	if(!in_loop){
		error("error: continue statement not within loop");	
	}
}
