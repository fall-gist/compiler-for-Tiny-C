#include "tree_sem.h"

extern int top_alloc;
extern int last_alloc;

void print_program(tree);
void print_ext_declaration(tree);
void print_declaration(tree);
void print_declaration(tree);
void print_declarator_list(tree);
void print_declarator(tree);
void print_funct_def(tree);
void print_param_type_list(tree);
void print_param_declaration(tree);
void print_state(tree);
void print_comp_state(tree);
void print_declaration_list(tree);
void print_state_list(tree);
void print_expr(tree);
void print_assign_expr(tree);
void print_logical_OR_expr(tree);
void print_logical_AND_expr(tree);
void print_equality_expr(tree);
void print_relation_expr(tree);
void print_add_expr(tree);
void print_mult_expr(tree);
void print_unary_expr(tree);
void print_postfix_expr(tree);
void print_prim_expr(tree);
void print_argu_expr_list(tree);
void print_identifier(tree);
void print_indent(int);