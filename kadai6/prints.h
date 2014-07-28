typedef struct c {	/* constant node */
	int op;
	int v;
} *constant;

typedef struct tk {	/* token node */
	int op;
	char *name;
} *token;

typedef struct tp {	/* n-tuple (n=4) */
	int op;
	union nd *a[4];
} *tuple;

typedef union nd {	/* tree */
	struct {
		int op;
	} n;
	struct tp tp;
	struct tk tk;
	struct c c;
} *tree;


tree make_tuple(int, tree, tree, tree, tree);
tree make_tuple1(int, tree);
tree make_tuple2(int, tree, tree);
tree make_tuple3(int, tree, tree, tree);
tree make_token_node(char *);
tree make_constant_node(int);

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
