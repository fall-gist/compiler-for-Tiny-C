#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emit.h"
#include "compiler.tab.h"

struct code *list_head;
struct code *list_tail;
int label_count = 1;
char *ret_label;	// そのとき見ている関数定義のリターンラベル。RETURN規則で用いる
char *loop_start;
char *loop_for;		// for文でcontinueのとき再初期化式を実行するためのラベル
char *loop_end;
int in_funct = 0;	// 関数定義内であるかどうかのフラグ。大域変数で用いる（emit_identifier()）
int in_for = 0, in_while = 0;	// for,while内のフラグ

struct code *emit(char *inst, char *op1, char *op2, char *label){
	char buf[80];
	struct code *c = (struct code *)malloc(sizeof(struct code));
	
	// ラベルがある場合、先頭に挿入
	if(label != NULL){
		if(inst == NULL)
			sprintf(buf, "%s:\n", label);
		else if(op1 == NULL)
			sprintf(buf, "%s\t%s\n", label, inst);
		else if(op2 == NULL)
			sprintf(buf, "%s\t%s\t%s\n", label, inst, op1);
		else
			sprintf(buf, "%s\t%s\t%s, %s\n", label, inst, op1, op2);
	}else{
		if(inst == NULL)
			buf[0] = '\0';
		else if(op1 == NULL)
			sprintf(buf, "\t%s\n", inst);
		else if(op2 == NULL)
			sprintf(buf, "\t%s\t%s\n", inst, op1);
		else
			sprintf(buf, "\t%s\t%s, %s\n", inst, op1, op2);
	}
	c->cd = strdup(buf);
	c->next = NULL;
	// コードリストの末尾に生成したコードを挿入
	if(list_tail != NULL){
		list_tail->next = c;
		list_tail = c;
	}else{
		list_tail = c;
		list_head = list_tail;
	}
	return c;
}

void print_code(){
	struct code *current = list_head;
	// 入力ファイルなし
	if(yyin == stdin){
		while(current->next != NULL){
			printf("%s", current->cd);
			current = current->next;
		}
		printf("%s", current->cd);
	// 入力ファイルありの場合、出力ファイルも決定済み
	}else{
		while(current->next != NULL){
			fprintf(yyout, "%s", current->cd);
			current = current->next;
		}
		fprintf(yyout, "%s", current->cd);
	}
}

// ラベルの生成　ラベルの個数n=1,2,... に対し、Ln というラベルを作る
char *make_label(){
	char *label;
	char n[80];
	char L[80] = "L";
	sprintf(n, "%d", label_count);
	label_count++;
	strcat(L, n);
	label = strdup(L);
	return label;
}

// リターンラベル　Lret関数名 の形（Lretfoo など）
char *make_ret_label(char *name){
	char *label;
	char ret[80] = "Lret";
	strcat(ret, name);
	label = strdup(ret);
	return label;
}

// 以下、主に構文木に沿ってコード生成を行う関数群

void emit_program(tree p){
	if(p->n.op == PRGM){
		emit_program(p->tp.a[0]);
		emit_ext_declaration(p->tp.a[1]);
	}else{
		emit_ext_declaration(p);
	}
}

void emit_ext_declaration(tree p){
	if(p->n.op == DECL){
		emit_declaration(p->tp.a[0]);
	}else{
		emit_funct_def(p);
	}
}

void emit_declaration(tree p){
	emit_declarator_list(p);
}

void emit_declarator_list(tree p){
	if(p->n.op == DECLARATORL){
		emit_declarator_list(p->tp.a[0]);
		emit_declassign(p->tp.a[1]);
	}else{
		emit_declassign(p);
	}
}

void emit_declassign(tree p){
	if(p->n.op == ASSIGN){
		if(p->tp.a[0]->tk.lev > 0)
			p->tp.a[0]->tk.offset = allocate_loc();
		emit_assign_expr(p);
	}else{
		if(p->tk.lev > 0)
			p->tk.offset = allocate_loc();
		emit_declarator(p);
	}
}

void emit_declarator(tree p){
	emit_identifier(p);
}

void emit_funct_def(tree p){
	in_funct = 1;
	
	char *funct_name = strdup(p->tp.a[0]->tk.name);
	ret_label = make_ret_label(funct_name);
	/*
		mac用
	char under[80] = "_";
	funct_name = strcat(under, funct_name);]
	*/
	
	emit("GLOBAL", funct_name, NULL, NULL);
	emit("push", "ebp", NULL, funct_name);
	emit("mov", "ebp", "esp", NULL);
	struct code *c = emit(NULL, NULL, NULL, NULL);
	if(p->tp.a[1] != NULL){
		emit_param_type_list(p->tp.a[1]);
	}
	emit_comp_state(p->tp.a[2]);
	if(top_alloc){
		char buf[80];
		sprintf(buf, "\tsub\tesp, %d\n", -top_alloc);
		c->cd = strdup(buf);
		emit("mov", "esp", "ebp", ret_label);
		emit("pop", "ebp", NULL, NULL);
	}else{
		emit("pop", "ebp", NULL, ret_label);
	}
	emit("ret", NULL, NULL, NULL);
	
	in_funct = 0;
}

void emit_param_type_list(tree p){
	if(p->n.op == PARAMTYPEL){
		emit_param_type_list(p->tp.a[0]);
		emit_param_declaration(p->tp.a[1]);
	}else{
		emit_param_declaration(p);
	}
}

void emit_param_declaration(tree p){
	emit_declarator(p);
}

void emit_state(tree p){
	switch(p->n.op){
		case EXPR:
			emit_expr(p->tp.a[0]);
			break;
		case CMPD_STM:
			emit_comp_state(p->tp.a[0]);
			break;
		case IF:{
			char *L1 = make_label(), *L2 = make_label();
			emit_expr(p->tp.a[0]);
			emit("cmp", "eax", "0", NULL);
			emit("je", L1, NULL, NULL);
			emit_state(p->tp.a[1]);
			if(p->tp.a[2] != NULL){
				emit("jmp", L2, NULL, NULL);
				emit(NULL, NULL, NULL, L1);
				emit_state(p->tp.a[2]);
				emit(NULL, NULL, NULL, L2);
			}else{
				emit(NULL, NULL, NULL, L1);	
			}
			break;
		}
		case WHILE:{
			in_while = 1;
			loop_start = make_label();
			loop_end = make_label();
			emit(NULL, NULL, NULL, loop_start);
			emit_expr(p->tp.a[0]);
			emit("cmp", "eax", "0", NULL);
			emit("je", loop_end, NULL, NULL);
			emit_state(p->tp.a[1]);
			emit("jmp", loop_start, NULL, NULL);
			emit(NULL, NULL, NULL, loop_end);
			in_while = 0;
			break;
		}
		case FOR:{
			in_for = 1;
			loop_start = make_label();
			loop_for = make_label();
			loop_end = make_label();
			if(p->tp.a[0] != NULL)
				emit_expr(p->tp.a[0]);
			emit(NULL, NULL, NULL, loop_start);
			if(p->tp.a[1] != NULL){
				emit_expr(p->tp.a[1]);
				emit("cmp", "eax", "0", NULL);
				emit("je", loop_end, NULL, NULL);
			}
			emit_state(p->tp.a[3]);
			if(p->tp.a[2] != NULL){
				emit(NULL, NULL, NULL, loop_for);
				emit_expr(p->tp.a[2]);
			}
			emit("jmp", loop_start, NULL, NULL);
			emit(NULL, NULL, NULL, loop_end);
			in_for = 0;
			break;
		}
		case RETURN:
			emit_expr(p->tp.a[0]);
			emit("jmp", ret_label, NULL, NULL);
			break;
		default:
			break;
	}
}

void emit_comp_state(tree p){
	int cur_loc = last_alloc;
	if(p->tp.a[0] != NULL){
		emit_declaration_list(p->tp.a[0]);
	}
	if(p->tp.a[1] != NULL){
		emit_state_list(p->tp.a[1]);
	}
	last_alloc = cur_loc;		// 関数定義内での局所変数割り当てを解放
}

void emit_declaration_list(tree p){
	if(p->n.op == DECLARATIONL){
		emit_declaration_list(p->tp.a[0]);
		emit_declaration(p->tp.a[1]);
	}else{
		emit_declaration(p);
	}
}

void emit_state_list(tree p){
	if(p->n.op == STATEL){
		emit_state_list(p->tp.a[0]);
		emit_state(p->tp.a[1]);
	}else{
		emit_state(p);
	}
}

void emit_expr(tree p){
	if(p->n.op == CONS){
		emit_expr(p->tp.a[0]);
		emit_assign_expr(p->tp.a[1]);
	}else if(p->n.op == BREAK){
		emit("jmp", loop_end, NULL, NULL);
	}else if(p->n.op == CONTINUE){
		if(in_for)
			emit("jmp", loop_for, NULL, NULL);
		else if(in_while)
			emit("jmp", loop_start, NULL, NULL);
	}else{
		emit_assign_expr(p);		
	}
}

void emit_assign_expr(tree p){
	if(p->n.op == ASSIGN){
		char loc[80] = "[", adrs[80];
		if(p->tp.a[0]->tk.lev == 0)
			// 大域変数
			sprintf(adrs, "%s]", p->tp.a[0]->tk.name);
		else if(p->tp.a[0]->tk.offset < 0){
			// 局所変数
			sprintf(adrs, "%d]", p->tp.a[0]->tk.offset);
			strcat(loc, "ebp");
		}else{
			sprintf(adrs, "+%d]", p->tp.a[0]->tk.offset);
			strcat(loc, "ebp");
		}
		strcat(loc, adrs);
		emit_logical_OR_expr(p->tp.a[1]);
		emit("mov", loc, "eax", NULL);
	}else{
		emit_logical_OR_expr(p);
	}
}

void emit_logical_OR_expr(tree p){
	if(p->n.op == OR){
		char temp[80] = "dword [ebp", adrs[80];
		char *label = make_label();
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit("mov", temp, "1", NULL);		//	初めは真に
		emit_logical_OR_expr(p->tp.a[0]);
		emit("cmp", "eax", "0", NULL);
		emit("jne", label, NULL, NULL);
		emit_logical_AND_expr(p->tp.a[1]);
		emit("cmp", "eax", "0", NULL);
		emit("jne", label, NULL, NULL);
		emit("mov", temp, "0", NULL);		// ともに偽でジャンプが起こらないなら偽に
		emit("mov", "eax", temp, label);
		
		release_loc();
	}else{
		emit_logical_AND_expr(p);
	}
}

void emit_logical_AND_expr(tree p){
	if(p->n.op == AND){
		char temp[80] = "dword [ebp", adrs[80];
		char *label = make_label();
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit("mov", temp, "0", NULL);		// 初めは偽に設定
		emit_logical_AND_expr(p->tp.a[0]);
		emit("cmp", "eax", "0", NULL);
		emit("je", label, NULL, NULL);
		emit_equality_expr(p->tp.a[1]);
		emit("cmp", "eax", "0", NULL);
		emit("je", label, NULL, NULL);
		emit("mov", temp, "1", NULL);		// ともに真なら真に
		emit("mov", "eax", temp, label);
		
		release_loc();
	}else{
		emit_equality_expr(p);
	}
}

void emit_equality_expr(tree p){
	if(p->n.op == EQ){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit_relation_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		emit_equality_expr(p->tp.a[0]);
		emit("cmp", "eax", temp, NULL);
		emit("sete", "al", NULL, NULL);
		emit("movzx", "eax", "al", NULL);
		
		release_loc();
	}else if(p->n.op == NE){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit_relation_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		emit_equality_expr(p->tp.a[0]);
		emit("cmp", "eax", temp, NULL);
		emit("setne", "al", NULL, NULL);
		emit("movzx", "eax", "al", NULL);
		
		release_loc();
	}else{
		emit_relation_expr(p);
	}
}

void emit_relation_expr(tree p){
	switch(p->n.op){
		case LT:{
			char temp[80] = "[ebp", adrs[80];
			sprintf(adrs, "%d]", allocate_loc());
			strcat(temp, adrs);
			
			emit_expr(p->tp.a[1]);
			emit("mov", temp, "eax", NULL);
			emit_relation_expr(p->tp.a[0]);
			emit("cmp", "eax", temp, NULL);
			emit("setl", "al", NULL, NULL);
			emit("movzx", "eax", "al", NULL);
			
			release_loc();
			break;
		}
		case MT:{
			char temp[80] = "[ebp", adrs[80];
			sprintf(adrs, "%d]", allocate_loc());
			strcat(temp, adrs);
			
			emit_expr(p->tp.a[1]);
			emit("mov", temp, "eax", NULL);
			emit_relation_expr(p->tp.a[0]);
			emit("cmp", "eax", temp, NULL);
			emit("setg", "al", NULL, NULL);
			emit("movzx", "eax", "al", NULL);
			
			release_loc();
			break;
		}
		case ELT:{
			char temp[80] = "[ebp", adrs[80];
			sprintf(adrs, "%d]", allocate_loc());
			strcat(temp, adrs);
			
			emit_expr(p->tp.a[1]);
			emit("mov", temp, "eax", NULL);
			emit_relation_expr(p->tp.a[0]);
			emit("cmp", "eax", temp, NULL);
			emit("setle", "al", NULL, NULL);
			emit("movzx", "eax", "al", NULL);
			
			release_loc();
			break;
		}
		case EMT:{
			char temp[80] = "[ebp", adrs[80];
			sprintf(adrs, "%d]", allocate_loc());
			strcat(temp, adrs);
			
			emit_expr(p->tp.a[1]);
			emit("mov", temp, "eax", NULL);
			emit_relation_expr(p->tp.a[0]);
			emit("cmp", "eax", temp, NULL);
			emit("setge", "al", NULL, NULL);
			emit("movzx", "eax", "al", NULL);
			
			release_loc();
			break;
		}
		default:
			emit_add_expr(p);
			break;
	}
}

void emit_add_expr(tree p){
	if(p->n.op == PLUS){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
			
		emit_mult_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		emit_add_expr(p->tp.a[0]);
		emit("add", "eax", temp, NULL);
		
		release_loc();
	}else if(p->n.op == MINUS){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit_mult_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		if(p->tp.a[0] == NULL) 
			emit("mov", "eax", "0", NULL);
		else
			emit_add_expr(p->tp.a[0]);
		emit("sub", "eax", temp, NULL);
		
		release_loc();
	}else{
		emit_mult_expr(p);
	}
}

void emit_mult_expr(tree p){
	if(p->n.op == TIMES){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
				
		emit_unary_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		emit_mult_expr(p->tp.a[0]);
		emit("imul", "eax", temp, NULL);
		
		release_loc();
	}else if(p->n.op == DIV){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit_unary_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		emit_mult_expr(p->tp.a[0]);
		emit("cdq", NULL, NULL, NULL);
		char d[80] = "dword ";
		strcat(d, temp);
		emit("idiv", d, NULL, NULL);
		
		release_loc();
	}else if(p->n.op == REMAIN){
		char temp[80] = "[ebp", adrs[80];
		sprintf(adrs, "%d]", allocate_loc());
		strcat(temp, adrs);
		
		emit_unary_expr(p->tp.a[1]);
		emit("mov", temp, "eax", NULL);
		emit_mult_expr(p->tp.a[0]);
		emit("cdq", NULL, NULL, NULL);
		char d[80] = "dword ";
		strcat(d, temp);
		emit("idiv", d, NULL, NULL);
		emit("mov", "eax", "edx", NULL);
		
		release_loc();
	}else{
		emit_unary_expr(p);
	}
}

void emit_unary_expr(tree p){
	if(p->n.op == NEG){
		emit_unary_expr(p->tp.a[0]);
		emit("imul", "eax", "-1", NULL);
	}else if(p->n.op == INC){
		emit_identifier(p->tp.a[0]);
		char adrs[80] = "[ebp", offset[80];
		if(p->tp.a[0]->tk.offset < 0){
			sprintf(offset, "%d", p->tp.a[0]->tk.offset);
		}else{
			sprintf(offset, "+%d", p->tp.a[0]->tk.offset);
		}
		strcat(adrs, offset);
		strcat(adrs, "]");
		emit("mov", "eax", adrs, NULL);
		emit("inc", "eax", NULL, NULL);
		emit("mov", adrs, "eax", NULL);
	}else if(p->n.op == DEC){
		emit_identifier(p->tp.a[0]);
		char adrs[80] = "[ebp", offset[80];
		if(p->tp.a[0]->tk.offset < 0){
			sprintf(offset, "%d", p->tp.a[0]->tk.offset);
		}else{
			sprintf(offset, "+%d", p->tp.a[0]->tk.offset);
		}
		strcat(adrs, offset);
		strcat(adrs, "]");
		emit("mov", "eax", adrs, NULL);
		emit("dec", "eax", NULL, NULL);
		emit("mov", adrs, "eax", NULL);
	}else{
		emit_postfix_expr(p);
	}
}

void emit_postfix_expr(tree p){
	if(p->n.op == FCALL){
		/*
			mac用
		char fname[80] = "_";
		strcat(fname, p->tp.a[0]->tk.name);
		*/
		char fname[80];
		strcpy(fname, p->tp.a[0]->tk.name);
		if(p->tp.a[0]->tk.kind == UNDEFFUN)
			emit("EXTERN", fname, NULL, NULL);
		if(p->tp.a[1] != NULL) {
			emit_argu_expr_list(p->tp.a[1]);
		}
		emit("call", fname, NULL, NULL);
		char args[20];
		sprintf(args, "%d", p->tp.a[0]->tk.offset * 4);
		emit("add", "esp", args, NULL);
	}else{
		 emit_prim_expr(p);
	}
}

void emit_prim_expr(tree p){
	if(p->n.op == IDENTIFIER){
		emit_identifier(p);
	}else if(p->n.op == CONST){
		char constant[80];
		sprintf(constant, "%d", p->c.v);
		emit("mov", "eax", constant, NULL);
	}else{
		emit_expr(p);
	}
}

void emit_argu_expr_list(tree p){
	if(p->n.op == ARGUEXPRL){
		emit_assign_expr(p->tp.a[1]);
		emit("push", "eax", NULL, NULL);
		emit_argu_expr_list(p->tp.a[0]);
	}else{
		emit_assign_expr(p);
		emit("push", "eax", NULL, NULL);
	}
}

void emit_identifier(tree p){
	if(p->n.op == IDENTIFIER){
		//大域変数の場合
		if(p->tk.lev == 0){
			// 関数定義内での参照
			if(in_funct){
				char name[80] = "[";	
				strcat(name, p->tk.name);
				strcat(name, "]");
				emit("mov", "eax", name, NULL);
			// 宣言
			}else{
				char cmn[80] = "COMMON\t";
				strcat(cmn, p->tk.name);
				emit(cmn, "4", NULL, NULL);
			}
		// 局所変数
		// 宣言なのか参照なのか判断できないので一律に生成
		}else{
			char adrs[80] = "[ebp", offset[80];
			if(p->tk.offset < 0){
				sprintf(offset, "%d", p->tk.offset);
			}else{
				sprintf(offset, "+%d", p->tk.offset);
			}
			strcat(adrs, offset);
			strcat(adrs, "]");
			emit("mov", "eax", adrs, NULL);
		}
	}
}
