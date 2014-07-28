%{
#include<stdio.h>
%}
%error_verbose

%token CONST IDENTIFIER
%token INT IF ELSE WHILE RETURN
%token PLUS MINUS TIMES DIV ASSIGN OR AND EQ NE LT MT ELT EMT

%%
program:
	ext_declaration
	| program ext_declaration
;
ext_declaration:
	declaration
	| funct_def
;
declaration:
	INT declarator_list ';'
;
declarator_list:
	declarator
	| declarator_list ',' declarator
;
declarator:
	IDENTIFIER
;
funct_def:
	INT declarator '(' param_type_list_opt ')' comp_state
;
param_type_list_opt:
	/*empty*/
	| param_type_list
;
param_type_list:
	param_declaration
	| param_type_list ',' param_declaration
;
param_declaration:
	INT declarator
;
state:
	';'
	| expr ';'
	| comp_state
	| IF '(' expr ')' state
	| IF '(' expr ')' state ELSE state
	| WHILE '(' expr ')' state
	| RETURN expr ';'
;
comp_state:
	'{' declaration_list_opt state_list_opt '}'
;
declaration_list_opt:
	/*empty*/
	| declaration_list
;
state_list_opt:
	/*empty*/
	| state_list
;
declaration_list:
	declaration
	| declaration_list declaration
;
state_list:
	state
	| state_list state
;
expr:
	assign_expr
	| expr ',' assign_expr
;
assign_expr:
	logical_OR_expr
	| IDENTIFIER ASSIGN assign_expr
;
logical_OR_expr:
	logical_AND_expr
	| logical_OR_expr OR logical_AND_expr
;
logical_AND_expr:
	equality_expr
	| logical_AND_expr AND equality_expr
;
equality_expr:
	relation_expr
	| equality_expr EQ relation_expr
	| equality_expr NE relation_expr
;
relation_expr:
	add_expr
	| relation_expr LT add_expr
	| relation_expr MT add_expr
	| relation_expr ELT add_expr
	| relation_expr EMT add_expr
;
add_expr:
	mult_expr
	| add_expr PLUS mult_expr
	| add_expr MINUS mult_expr	
;
mult_expr:
	unary_expr
	| mult_expr TIMES unary_expr
	| mult_expr DIV unary_expr
;
unary_expr:
	postfix_expr
	| MINUS unary_expr
;
postfix_expr:
	prim_expr
	| IDENTIFIER '(' argu_expr_list_opt ')'
;
argu_expr_list_opt:
	/*empty*/
	| argu_expr_list
;
prim_expr:
	IDENTIFIER
	| CONST
	| '(' expr ')'
;
argu_expr_list:
	assign_expr
	| argu_expr_list ',' assign_expr
;

%%
extern int yylineno;

int yyerror(char *s){
	fprintf(stderr, "%d: %s\n", yylineno, s);
	return 0;
}
main(){
	yyparse();
}