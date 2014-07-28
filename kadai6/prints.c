#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "prints.h"
#include "tree.tab.h"

int count;

tree make_tuple(int opr, tree n0, tree n1, tree n2, tree n3){
	tree t=(tree)malloc(sizeof(union nd));
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
	t->tk.op = IDENTIFIER;
	t->tk.name = strdup(str);
	return t;
}

tree make_constant_node(int i){
	tree t = (tree)malloc(sizeof(union nd));
	t->c.op = CONST;
	t->c.v = i;
	return t;
}


void print_program(tree p){
	if(p->n.op == PRGM){
		print_program(p->tp.a[0]);
		print_ext_declaration(p->tp.a[1]);
		printf("\n");
	}else{
		print_ext_declaration(p);
		printf("\n");
	}
}

void print_ext_declaration(tree p){
	count = 1;
	if(p->n.op == DECL){
		print_declaration(p->tp.a[0]);
	}else{
		printf("(");
		print_funct_def(p);
		printf(")");
	}
}

void print_declaration(tree p){
	printf("(int ");
	print_declarator_list(p);
	printf(")");
}

void print_declarator_list(tree p){
	if(p->n.op == DECLARATORL){
		print_declarator_list(p->tp.a[0]);
		printf(" ");
		print_declarator(p->tp.a[1]);
	}else{
		print_declarator(p);
	}
}

void print_declarator(tree p){
	print_identifier(p);
}

void print_funct_def(tree p){
	printf("(int ");
	print_declarator(p->tp.a[0]);
	printf(")");
	if(p->tp.a[1] != NULL){
		printf(" ");
		printf("(");
		print_param_type_list(p->tp.a[1]);
		printf(")");
	}
	printf("\n(\n");
	print_comp_state(p->tp.a[2]);
	printf("\n)");
}

void print_param_type_list(tree p){
	if(p->n.op == PARAMTYPEL){
		print_param_type_list(p->tp.a[0]);
		printf(" ");
		print_param_declaration(p->tp.a[1]);
	}else{
		print_param_declaration(p);
	}
}

void print_param_declaration(tree p){
	printf("(int ");
	print_declarator(p);
	printf(")");
}

void print_state(tree p){
	switch(p->n.op){
		case EXPR:
			print_expr(p->tp.a[0]);
			break;
		case CMPD_STM:
			print_comp_state(p->tp.a[0]);
			break;
		case IF:
			printf("(IF ");
			count++;
			print_expr(p->tp.a[0]);
			printf("\n");
			if(p->tp.a[1]->n.op != CMPD_STM) print_indent(count);
			print_state(p->tp.a[1]);
			count--;
			if(p->tp.a[2] != NULL){
				printf("\n");
				print_indent(count);
				printf(")");
				printf("(ELSE\n");
				count++;
				if(p->tp.a[1]->n.op != CMPD_STM) print_indent(count);
				else if(p->tp.a[2]->n.op == IF) print_indent(count);
				print_state(p->tp.a[2]);
				count--;
			}
			printf("\n");
			print_indent(count);
			printf(")");
			break;
		case WHILE:
			printf("(WHILE ");
			count++;
			print_expr(p->tp.a[0]);
			printf("\n");
			if(p->tp.a[1]->n.op != CMPD_STM) print_indent(count);
			print_state(p->tp.a[1]);
			count--;
			printf("\n");
			print_indent(count);
			printf(")");
			break;
		case RETURN:
			printf("(RETURN ");
			print_expr(p->tp.a[0]);
			printf(")");
			break;
		default:
			break;
	}
}

void print_comp_state(tree p){
	if(p->tp.a[0] != NULL){
		print_declaration_list(p->tp.a[0]);
		printf("\n");
	}
	if(p->tp.a[1] != NULL){
		print_state_list(p->tp.a[1]);
	}
}

void print_declaration_list(tree p){
	if(p->n.op == DECLARATIONL){
		print_declaration_list(p->tp.a[0]);
		printf("\n");
		print_indent(count);
		print_declaration(p->tp.a[1]);
	}else{
		print_indent(count);
		print_declaration(p);
	}
}

void print_state_list(tree p){
	if(p->n.op == STATEL){
		print_state_list(p->tp.a[0]);
		printf("\n");
		print_indent(count);
		print_state(p->tp.a[1]);
	}else{
		print_indent(count);
		print_state(p);
	}
}

void print_expr(tree p){
	if(p->n.op == CONS){
		print_expr(p->tp.a[0]);
		printf(" ");
		print_assign_expr(p->tp.a[1]);
	}else{
		print_assign_expr(p);		
	}
}

void print_assign_expr(tree p){
	if(p->n.op == ASSIGN){
		printf("(= ");
		print_identifier(p->tp.a[0]);
		printf(" ");
		print_logical_OR_expr(p->tp.a[1]);
		printf(")");
	}else{
		print_logical_OR_expr(p);
	}
}

void print_logical_OR_expr(tree p){
	if(p->n.op == OR){
		printf("(|| ");
		print_logical_OR_expr(p->tp.a[0]);
		printf(" ");
		print_logical_AND_expr(p->tp.a[1]);
		printf(")");
	}else{
		print_logical_AND_expr(p);
	}
}

void print_logical_AND_expr(tree p){
	if(p->n.op == AND){
		printf("(&& ");
		print_logical_AND_expr(p->tp.a[0]);
		printf(" ");
		print_equality_expr(p->tp.a[1]);
		printf(")");
	}else{
		print_equality_expr(p);
	}
}

void print_equality_expr(tree p){
	if(p->n.op == EQ){
		printf("(== ");
		print_equality_expr(p->tp.a[0]);
		printf(" ");
		print_relation_expr(p->tp.a[1]);
		printf(")");
	}else if(p->n.op == NE){
		printf("(!= ");
		print_equality_expr(p->tp.a[0]);
		printf(" ");
		print_relation_expr(p->tp.a[1]);
		printf(")");
	}else{
		print_relation_expr(p);
	}
}

void print_relation_expr(tree p){
	switch(p->n.op){
		case LT:
			printf("(< ");
			print_relation_expr(p->tp.a[0]);
			printf(" ");
			print_add_expr(p->tp.a[1]);
			printf(")");
			break;
		case MT:
			printf("(> ");
			print_relation_expr(p->tp.a[0]);
			printf(" ");
			print_add_expr(p->tp.a[1]);
			printf(")");
			break;
		case ELT:
			printf("(<= ");
			print_relation_expr(p->tp.a[0]);
			printf(" ");
			print_add_expr(p->tp.a[1]);
			printf(")");
			break;
		case EMT:
			printf("(>= ");
			print_relation_expr(p->tp.a[0]);
			printf(" ");
			print_add_expr(p->tp.a[1]);
			printf(")");
			break;
		default:
			print_add_expr(p);
			break;
	}
}

void print_add_expr(tree p){
	if(p->n.op == PLUS){
		printf("(+ ");
		print_add_expr(p->tp.a[0]);
		printf(" ");
		print_mult_expr(p->tp.a[1]);
		printf(")");
	}else if(p->n.op == MINUS){
		if(p->tp.a[0] == NULL){
			print_mult_expr(p->tp.a[1]);
		}else{
			printf("(- ");
			print_add_expr(p->tp.a[0]);
			printf(" ");
			print_mult_expr(p->tp.a[1]);
			printf(")");
		}
	}else{
		print_mult_expr(p);
	}
}

void print_mult_expr(tree p){
	if(p->n.op == TIMES){
		printf("(* ");
		print_mult_expr(p->tp.a[0]);
		printf(" ");
		print_unary_expr(p->tp.a[1]);
		printf(")");
	}else if(p->n.op == DIV){
		printf("(/ ");
		print_mult_expr(p->tp.a[0]);
		printf(" ");
		print_unary_expr(p->tp.a[1]);
		printf(")");
	}else{
		print_unary_expr(p);
	}
}

void print_unary_expr(tree p){
	if(p->n.op == NEG){
		printf("-");
		print_unary_expr(p->tp.a[0]);
	}else{
		print_postfix_expr(p);
	}
}

void print_postfix_expr(tree p){
	if(p->n.op == FCALL){
		 printf("(FCALL ");
		 print_identifier(p->tp.a[0]);
		 if(p->tp.a[1] != NULL) {
			 printf(" ");
			 print_argu_expr_list(p->tp.a[1]);
		 }
		 printf(")");
	}else{
		 print_prim_expr(p);
	}
}

void print_prim_expr(tree p){
	if(p->n.op == IDENTIFIER){
		print_identifier(p);
	}else if(p->n.op == CONST){
		printf("%d", p->c.v);
	}else{
		print_expr(p);
	}
}

void print_argu_expr_list(tree p){
	if(p->n.op == ARGUEXPRL){
		print_argu_expr_list(p->tp.a[0]);
		printf(" ");
		print_assign_expr(p->tp.a[1]);
	}else{
		print_assign_expr(p);
	}
}

void print_identifier(tree p){
	if(p->n.op == IDENTIFIER)
		printf("%s", p->tk.name);
}

void print_indent(int i){
	for( ; i>0; i--) printf("  ");
}
