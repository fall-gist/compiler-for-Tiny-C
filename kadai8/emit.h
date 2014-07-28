#include "tree.h"

extern int top_alloc;
extern int last_alloc;

struct code{
	char *cd;
	struct code *next;
};

struct code *emit(char *, char *, char *, char *);
void emit_program(tree);
void print_code();
char *make_label();
char *make_ret_label();
void emit_program(tree);
void emit_ext_declaration(tree);
void emit_declaration(tree);
void emit_declaration(tree);
void emit_declarator_list(tree);
void emit_declarator(tree);
void emit_funct_def(tree);
void emit_param_type_list(tree);
void emit_param_declaration(tree);
void emit_state(tree);
void emit_comp_state(tree);
void emit_declaration_list(tree);
void emit_state_list(tree);
void emit_expr(tree);
void emit_assign_expr(tree);
void emit_logical_OR_expr(tree);
void emit_logical_AND_expr(tree);
void emit_equality_expr(tree);
void emit_relation_expr(tree);
void emit_add_expr(tree);
void emit_mult_expr(tree);
void emit_unary_expr(tree);
void emit_postfix_expr(tree);
void emit_prim_expr(tree);
void emit_argu_expr_list(tree);
void emit_identifier(tree);