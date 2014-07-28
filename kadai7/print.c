#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print.h"
#include "semantic.tab.h"

int count;

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
	count=1;
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
		if(p->tp.a[1]->tk.lev > 0)
			p->tp.a[1]->tk.offset = allocate_loc();
		print_declarator(p->tp.a[1]);
	}else{
		if(p->tk.lev > 0)
			p->tk.offset = allocate_loc();
		print_declarator(p);
	}
}

void print_declarator(tree p){
	print_identifier(p);
	if(p->tk.lev > 0)
		printf(":%d", p->tk.offset);
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
			printf("(\n");
			count++;
			print_comp_state(p->tp.a[0]);
			printf("\n");
			count--;
			print_indent(count);
			printf(")");
			break;
		case IF:
			printf("(IF ");
			count++;
			print_expr(p->tp.a[0]);
			printf("\n");
			print_indent(count);
			if(p->tp.a[1]->n.op != CMPD_STM){
				printf("(\n");
				count++;
				print_indent(count);			
			}
			print_state(p->tp.a[1]);
			if(p->tp.a[1]->n.op != CMPD_STM){
				printf("\n");
				count--;
				print_indent(count);
				printf(")");
			}
			count--;
			if(p->tp.a[2] != NULL){
				printf("\n");
				print_indent(count);
				printf(")");
				printf("(ELSE\n");
				if(p->tp.a[2]->n.op != CMPD_STM){
					count++;
					print_indent(count);
					printf("(\n");
				}
				count++;
				print_indent(count);
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
			print_indent(count);
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
	int cur_last_alloc = last_alloc;
	if(p->tp.a[0] != NULL){
		print_declaration_list(p->tp.a[0]);
		printf("\n");
	}
	if(p->tp.a[1] != NULL){
		print_state_list(p->tp.a[1]);
	}
	last_alloc = cur_last_alloc;
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
		if(p->tp.a[0] == NULL) print_mult_expr(p->tp.a[1]);
		else{
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
		printf("%d",p->c.v);
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
	if(p->n.op == IDENTIFIER)	printf("%s:%d", p->tk.name, p->tk.lev);
}

void print_indent(int i){
	for(; i>0; i--) printf("  ");
}