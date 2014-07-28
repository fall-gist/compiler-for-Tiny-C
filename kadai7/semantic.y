%{
#include<stdio.h>
#include "tree_sem.h"
#include "print.h"
int cur_lev;
int number_of_param = 0;
%}
%error_verbose

%token <i> CONST 
%token <n> IDENTIFIER
%token <str> INT IF ELSE WHILE RETURN
%token <str> PLUS MINUS TIMES DIV ASSIGN OR AND EQ NE LT MT ELT EMT NEG
%token <str> CONS
%token PRGM
%token DECL
%token FUNDEF
%token PARAM_DECL
%token CMPD_STM
%token EXPR
%token FCALL
%token DECLARATIONL
%token DECLARATORL
%token STATEL
%token PARAMTYPEL
%token ARGUEXPRL
%type <n> main
%type <n> program
%type <n> ext_declaration
%type <n> declaration
%type <n> declarator_list
%type <n> declarator
%type <n> funct_def
%type <n> param_type_list_opt
%type <n> param_type_list
%type <n> param_declaration
%type <n> state
%type <n> comp_state
%type <n> declaration_list_opt
%type <n> state_list_opt
%type <n> declaration_list
%type <n> state_list
%type <n> expr
%type <n> assign_expr
%type <n> logical_OR_expr
%type <n> logical_AND_expr
%type <n> equality_expr
%type <n> relation_expr
%type <n> add_expr
%type <n> mult_expr
%type <n> unary_expr
%type <n> postfix_expr
%type <n> argu_expr_list_opt
%type <n> prim_expr
%type <n> argu_expr_list

%union{
	int i;
	char *str;
	tree n;
}
%%
main:
		{ symtab = NULL; cur_lev = 0; }
	program
		{ if (yynerrs == 0 && semnerrs == 0) print_program($2); }
;
program:
	ext_declaration
	| program ext_declaration
		{ $$ = make_tuple2(PRGM, $1, $2); }
;
ext_declaration:
	declaration
		{ $$ = make_tuple1(DECL, $1); }
	| funct_def
;
declaration:
	INT declarator_list ';'
		{ $$ = $2; }
;
declarator_list:
	declarator
		{ $$ = make_decl($1); }
	| declarator_list ',' declarator
		{ $$ = make_tuple2(DECLARATORL, $1, make_decl($3)); }
;
declarator:
	IDENTIFIER
;
funct_def:
	INT declarator '('
		{ make_fun_def($2); cur_lev++; }
	param_type_list_opt 
		{ set_offset($2); }
	')' comp_state
		{ $$ = make_tuple3(FUNDEF, $2, $5, $8);	number_of_param = 0; pop(cur_lev); cur_lev--; }
;
param_type_list_opt:
	/*empty*/
		{ $$ = NULL; }
	| param_type_list
;
param_type_list:
	param_declaration
	| param_type_list ',' param_declaration
		{ $$ = make_tuple2(PARAMTYPEL, $1, $3); }
;
param_declaration:
	INT declarator
		{ $$ = make_parm_decl($2); number_of_param++; set_offset($$); }
;
state:
	';'
		{ $$ = NULL; }
	| expr ';'
		{ $$ = make_tuple1(EXPR, $1); }
	| comp_state
		{ $$ = make_tuple1(CMPD_STM, $1); }
	| IF '(' expr ')' state
		{ $$ = make_tuple2(IF, $3, $5); }
	| IF '(' expr ')' state ELSE state
		{ $$ = make_tuple3(IF, $3, $5, $7); }
	| WHILE '(' expr ')' state
		{ $$ = make_tuple2(WHILE, $3, $5); }
	| RETURN expr ';'
		{ $$ = make_tuple1(RETURN, $2); }
;
comp_state:
	'{'
		{ cur_lev++; }
	declaration_list_opt state_list_opt '}'
		{ $$ = make_tuple2(CONS, $3, $4); pop(cur_lev); cur_lev--; }
;
declaration_list_opt:
	/*empty*/
		{ $$ = NULL; }
	| declaration_list
;
state_list_opt:
	/*empty*/
		{ $$ = NULL; }
	| state_list
;
declaration_list:
	declaration
	| declaration_list declaration
		{ $$ = make_tuple2(DECLARATIONL, $1, $2); }
;
state_list:
	state
	| state_list state
		{ $$ = make_tuple2(STATEL, $1, $2); }
;
expr:
	assign_expr
	| expr ',' assign_expr
		{ $$ = make_tuple2(CONS, $1, $3); }
;
assign_expr:
	logical_OR_expr
	| IDENTIFIER ASSIGN assign_expr
		{ $$ = make_tuple2(ASSIGN, $1, $3); }
;
logical_OR_expr:
	logical_AND_expr
	| logical_OR_expr OR logical_AND_expr
		{ $$ = make_tuple2(OR, $1, $3); }
;
logical_AND_expr:
	equality_expr
	| logical_AND_expr AND equality_expr
		{ $$ = make_tuple2(AND, $1, $3); }
;
equality_expr:
	relation_expr
	| equality_expr EQ relation_expr
		{ $$ = make_tuple2(EQ, $1, $3); }
	| equality_expr NE relation_expr
		{ $$ = make_tuple2(NE, $1, $3); }
;
relation_expr:
	add_expr
	| relation_expr LT add_expr
		{ $$ = make_tuple2(LT, $1, $3); }
	| relation_expr MT add_expr
		{ $$ = make_tuple2(MT, $1, $3); }
	| relation_expr ELT add_expr
		{ $$ = make_tuple2(ELT, $1, $3); }
	| relation_expr EMT add_expr
		{ $$ = make_tuple2(EMT, $1, $3); }
;
add_expr:
	mult_expr
	| add_expr PLUS mult_expr
		{ $$ = make_tuple2(PLUS, $1, $3); }
	| add_expr MINUS mult_expr
		{ $$ = make_tuple2(MINUS, $1, $3); }
;
mult_expr:
	unary_expr
	| mult_expr TIMES unary_expr
		{ $$ = make_tuple2(TIMES, $1, $3); }
	| mult_expr DIV unary_expr
		{ $$ = make_tuple2(DIV, $1, $3); }
;
unary_expr:
	postfix_expr
	| MINUS unary_expr
		{ $$ = make_tuple1(NEG, $2); }
;
postfix_expr:
	prim_expr
	| IDENTIFIER '(' argu_expr_list_opt ')'
		{ $$ = make_tuple2(FCALL, ref_fun($1), $3); chkarg($1); }

;
argu_expr_list_opt:
	/*empty*/
		{ $$ = NULL; }
	| argu_expr_list
;
prim_expr:
	IDENTIFIER
		{ $$ = ref_var($1); }
	| CONST
		{ $$ = make_constant_node($1); }
	| '(' expr ')'
		{ $$ = $2; }
;
argu_expr_list:
	assign_expr
	| argu_expr_list ',' assign_expr
		{ $$ = make_tuple2(ARGUEXPRL, $1, $3); }
;

%%
int yyerror(char *s){
	fprintf(stderr,  "%d: %s\n",  yylineno,  s);
	return 0;
}
main(){
	yyparse();
}
