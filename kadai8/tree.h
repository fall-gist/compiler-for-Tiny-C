#ifndef tree_h
#define tree_h

typedef struct c {  /* constant node */
	int op;
	int v;
} *constant;

typedef struct tk {  /* token node */
	int op;
	struct tk *next;
	char *name;
	int lev;
	enum {FRESH, VAR, FUN, PARM, UNDEFFUN} kind;
	int offset;
} *token;

typedef struct tp {  /* n-tuple (n=4) */
	int op;
	union nd *a[4];
} *tuple;

typedef union nd {  /* tree */
	struct {
		int op;
	} n;
	struct tp tp;
	struct tk tk;
	struct c c;
} *tree;


extern int cur_lev;
extern int yylineno;
extern int semnerrs;
extern token symtab;
extern int number_of_param;
extern int number_of_arg;


tree make_tuple(int, tree, tree, tree, tree);
tree make_tuple1(int, tree);
tree make_tuple2(int, tree, tree);
tree make_tuple3(int, tree, tree, tree);
tree make_token_node(char *);
tree make_constant_node(int);
tree make_decl(tree);
tree make_parm_decl(tree);
tree make_fun_def(tree);
tree ref_var(tree);
tree ref_fun(tree);
tree lookup_sym(char *);
void globalize_sym(tree);
void error(char *, ...);
void warn(char *, ...);
void pop(int);
void set_offset(tree);
void chkarg(tree);
int allocate_loc();
void release_loc();

#endif