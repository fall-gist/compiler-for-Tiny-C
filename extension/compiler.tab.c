/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "compiler.y"

#include<stdio.h>
#include "tree.h"
#include "emit.h"
#include "peephole.h"
int cur_lev;
int number_of_param = 0;
int in_loop = 0;
extern struct code *list_head;
extern struct code *list_tail;


/* Line 268 of yacc.c  */
#line 84 "compiler.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONST = 258,
     IDENTIFIER = 259,
     INT = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     FOR = 264,
     BREAK = 265,
     CONTINUE = 266,
     RETURN = 267,
     PLUS = 268,
     MINUS = 269,
     TIMES = 270,
     DIV = 271,
     REMAIN = 272,
     ASSIGN = 273,
     ADDASSIGN = 274,
     SUBASSIGN = 275,
     MULASSIGN = 276,
     DIVASSIGN = 277,
     REMASSIGN = 278,
     OR = 279,
     AND = 280,
     EQ = 281,
     NE = 282,
     LT = 283,
     MT = 284,
     ELT = 285,
     EMT = 286,
     NEG = 287,
     INC = 288,
     DEC = 289,
     CONS = 290,
     PRGM = 291,
     DECL = 292,
     FUNDEF = 293,
     PARAM_DECL = 294,
     CMPD_STM = 295,
     EXPR = 296,
     FCALL = 297,
     DECLARATIONL = 298,
     DECLARATORL = 299,
     STATEL = 300,
     PARAMTYPEL = 301,
     ARGUEXPRL = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 68 "compiler.y"

	int i;
	char *str;
	tree n;



/* Line 293 of yacc.c  */
#line 175 "compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 187 "compiler.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    20,
      22,    26,    28,    32,    34,    35,    36,    45,    46,    48,
      50,    54,    57,    59,    62,    64,    70,    78,    79,    86,
      87,    98,   102,   103,   109,   110,   112,   113,   115,   117,
     120,   122,   125,   126,   128,   130,   134,   136,   138,   140,
     144,   148,   152,   156,   160,   164,   166,   170,   172,   176,
     178,   182,   186,   188,   192,   196,   200,   204,   206,   210,
     214,   216,   220,   224,   228,   230,   233,   236,   239,   241,
     246,   247,   249,   251,   253,   257,   259
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    56,    57,    -1,    58,    -1,    57,
      58,    -1,    59,    -1,    63,    -1,     5,    60,    48,    -1,
      61,    -1,    60,    49,    61,    -1,    62,    -1,    62,    18,
      80,    -1,     4,    -1,    -1,    -1,     5,    62,    50,    64,
      66,    65,    51,    72,    -1,    -1,    67,    -1,    68,    -1,
      67,    49,    68,    -1,     5,    62,    -1,    48,    -1,    79,
      48,    -1,    72,    -1,     6,    50,    79,    51,    69,    -1,
       6,    50,    79,    51,    69,     7,    69,    -1,    -1,     8,
      70,    50,    79,    51,    69,    -1,    -1,     9,    71,    50,
      78,    48,    78,    48,    78,    51,    69,    -1,    12,    79,
      48,    -1,    -1,    52,    73,    74,    75,    53,    -1,    -1,
      76,    -1,    -1,    77,    -1,    59,    -1,    76,    59,    -1,
      69,    -1,    77,    69,    -1,    -1,    79,    -1,    80,    -1,
      79,    49,    80,    -1,    10,    -1,    11,    -1,    81,    -1,
       4,    18,    80,    -1,     4,    19,    80,    -1,     4,    20,
      80,    -1,     4,    21,    80,    -1,     4,    22,    80,    -1,
       4,    23,    80,    -1,    82,    -1,    81,    24,    82,    -1,
      83,    -1,    82,    25,    83,    -1,    84,    -1,    83,    26,
      84,    -1,    83,    27,    84,    -1,    85,    -1,    84,    28,
      85,    -1,    84,    29,    85,    -1,    84,    30,    85,    -1,
      84,    31,    85,    -1,    86,    -1,    85,    13,    86,    -1,
      85,    14,    86,    -1,    87,    -1,    86,    15,    87,    -1,
      86,    16,    87,    -1,    86,    17,    87,    -1,    88,    -1,
      14,    87,    -1,    33,     4,    -1,    34,     4,    -1,    90,
      -1,     4,    50,    89,    51,    -1,    -1,    91,    -1,     4,
      -1,     3,    -1,    50,    79,    51,    -1,    80,    -1,    91,
      49,    80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    75,    91,    92,    96,    98,   101,   105,
     106,   110,   112,   116,   120,   122,   119,   129,   130,   133,
     134,   138,   142,   144,   146,   148,   150,   153,   152,   157,
     156,   160,   165,   164,   171,   172,   176,   177,   180,   181,
     185,   186,   191,   192,   195,   196,   198,   200,   204,   205,
     207,   209,   211,   213,   215,   219,   220,   224,   225,   229,
     230,   232,   236,   237,   239,   241,   243,   247,   248,   250,
     254,   255,   257,   259,   263,   264,   266,   268,   272,   273,
     278,   279,   282,   284,   286,   290,   291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "IDENTIFIER", "INT", "IF",
  "ELSE", "WHILE", "FOR", "BREAK", "CONTINUE", "RETURN", "PLUS", "MINUS",
  "TIMES", "DIV", "REMAIN", "ASSIGN", "ADDASSIGN", "SUBASSIGN",
  "MULASSIGN", "DIVASSIGN", "REMASSIGN", "OR", "AND", "EQ", "NE", "LT",
  "MT", "ELT", "EMT", "NEG", "INC", "DEC", "CONS", "PRGM", "DECL",
  "FUNDEF", "PARAM_DECL", "CMPD_STM", "EXPR", "FCALL", "DECLARATIONL",
  "DECLARATORL", "STATEL", "PARAMTYPEL", "ARGUEXPRL", "';'", "','", "'('",
  "')'", "'{'", "'}'", "$accept", "main", "$@1", "program",
  "ext_declaration", "declaration", "declarator_list", "decl_assign",
  "declarator", "funct_def", "$@2", "$@3", "param_type_list_opt",
  "param_type_list", "param_declaration", "state", "$@4", "$@5",
  "comp_state", "$@6", "declaration_list_opt", "state_list_opt",
  "declaration_list", "state_list", "expr_opt", "expr", "assign_expr",
  "logical_OR_expr", "logical_AND_expr", "equality_expr", "relation_expr",
  "add_expr", "mult_expr", "unary_expr", "postfix_expr",
  "argu_expr_list_opt", "prim_expr", "argu_expr_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    59,    44,
      40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    56,    55,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    64,    65,    63,    66,    66,    67,
      67,    68,    69,    69,    69,    69,    69,    70,    69,    71,
      69,    69,    73,    72,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    87,    87,    88,    88,
      89,    89,    90,    90,    90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     1,
       3,     1,     3,     1,     0,     0,     8,     0,     1,     1,
       3,     2,     1,     2,     1,     5,     7,     0,     6,     0,
      10,     3,     0,     5,     0,     1,     0,     1,     1,     2,
       1,     2,     0,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     1,     4,
       0,     1,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     4,     6,     7,    13,
       0,     9,    11,     5,     8,     0,     0,    14,    10,    11,
      83,    82,     0,     0,     0,     0,    12,    48,    55,    57,
      59,    62,    67,    70,    74,    78,    17,     0,     0,     0,
       0,     0,     0,    80,    82,    75,    76,    77,    46,    47,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    18,    19,    49,
      50,    51,    52,    53,    54,    85,     0,    81,     0,    84,
      56,    58,    60,    61,    63,    64,    65,    66,    68,    69,
      71,    72,    73,    21,     0,     0,    79,     0,    45,     0,
      20,    86,    32,    16,    34,     0,    38,    36,    35,     0,
      27,    29,     0,    22,    40,    24,     0,    37,     0,    39,
       0,     0,     0,     0,    33,    41,    23,     0,     0,    42,
      31,     0,     0,     0,    43,    25,     0,    42,     0,    28,
       0,    26,    42,     0,     0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    10,    11,    19,     8,
      36,    94,    66,    67,    68,   114,   121,   122,   115,   104,
     107,   116,   108,   117,   133,   118,    51,    27,    28,    29,
      30,    31,    32,    33,    34,    76,    35,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int8 yypact[] =
{
    -124,     2,     3,  -124,    13,     3,  -124,  -124,  -124,  -124,
      60,  -124,     0,  -124,  -124,    13,    28,  -124,  -124,    15,
    -124,    47,    40,    17,    34,    26,  -124,    21,    27,    62,
      63,    97,    90,  -124,  -124,  -124,    51,    28,    28,    28,
      28,    28,    28,    28,    25,  -124,  -124,  -124,  -124,  -124,
     -10,  -124,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    13,  -124,    22,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,    29,    35,    28,  -124,
      27,    62,    63,    63,    97,    97,    97,    97,    90,    90,
    -124,  -124,  -124,  -124,    45,    51,  -124,    28,  -124,    50,
    -124,  -124,  -124,  -124,    81,    13,  -124,     1,    81,    70,
    -124,  -124,    26,  -124,  -124,  -124,    71,     1,    65,  -124,
      26,    73,    75,    67,  -124,  -124,  -124,     6,    26,    26,
    -124,     1,    32,    78,    79,   120,     1,    26,     1,  -124,
      82,  -124,    26,    80,     1,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,  -124,  -124,   124,   -88,  -124,   117,    -1,  -124,
    -124,  -124,  -124,  -124,    38,   -59,  -124,  -124,    36,  -124,
    -124,  -124,  -124,  -124,  -123,   -25,   -15,  -124,    84,    85,
      64,    42,    61,   -16,  -124,  -124,  -124,  -124
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,    26,     3,    12,    20,    21,    45,   109,     4,   110,
     111,    48,    49,   112,   140,    22,   106,     9,    16,   143,
     119,    46,    69,    70,    71,    72,    73,    74,    75,    20,
      21,    20,    21,    16,    23,    24,    48,    49,    47,    78,
      22,    79,    22,    20,    44,    52,    90,    91,    92,   113,
      17,    25,    53,   102,    22,    78,    65,   131,   125,    23,
      24,    23,    24,    98,    93,    37,    38,    39,    40,    41,
      42,    95,   135,    23,    24,    43,    25,   139,    25,   141,
      96,    78,   101,   136,    97,   145,   105,   123,    54,    55,
      25,    56,    57,    58,    59,   127,    99,    43,    84,    85,
      86,    87,   102,   132,   134,    62,    63,    64,    14,    15,
      60,    61,   134,   126,    78,   130,    78,   134,    82,    83,
     120,    88,    89,   128,   124,   129,   137,   138,    78,    13,
     142,   144,    18,   100,     0,   103,    80,     0,    81
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-124))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      25,    16,     0,     4,     3,     4,    22,     6,     5,     8,
       9,    10,    11,    12,   137,    14,   104,     4,    18,   142,
     108,     4,    37,    38,    39,    40,    41,    42,    43,     3,
       4,     3,     4,    18,    33,    34,    10,    11,     4,    49,
      14,    51,    14,     3,     4,    24,    62,    63,    64,    48,
      50,    50,    25,    52,    14,    49,     5,    51,   117,    33,
      34,    33,    34,    78,    65,    18,    19,    20,    21,    22,
      23,    49,   131,    33,    34,    50,    50,   136,    50,   138,
      51,    49,    97,    51,    49,   144,     5,   112,    26,    27,
      50,    28,    29,    30,    31,   120,    51,    50,    56,    57,
      58,    59,    52,   128,   129,    15,    16,    17,    48,    49,
      13,    14,   137,    48,    49,    48,    49,   142,    54,    55,
      50,    60,    61,    50,    53,    50,    48,     7,    49,     5,
      48,    51,    15,    95,    -1,    99,    52,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     5,    57,    58,    59,    63,     4,
      60,    61,    62,    58,    48,    49,    18,    50,    61,    62,
       3,     4,    14,    33,    34,    50,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    90,    64,    18,    19,    20,
      21,    22,    23,    50,     4,    87,     4,     4,    10,    11,
      79,    80,    24,    25,    26,    27,    28,    29,    30,    31,
      13,    14,    15,    16,    17,     5,    66,    67,    68,    80,
      80,    80,    80,    80,    80,    80,    89,    91,    49,    51,
      82,    83,    84,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    62,    65,    49,    51,    49,    80,    51,
      68,    80,    52,    72,    73,     5,    59,    74,    76,     6,
       8,     9,    12,    48,    69,    72,    75,    77,    79,    59,
      50,    70,    71,    79,    53,    69,    48,    79,    50,    50,
      48,    51,    79,    78,    79,    69,    51,    48,     7,    69,
      78,    69,    48,    78,    51,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 75 "compiler.y"
    { symtab = NULL; cur_lev = 0; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 77 "compiler.y"
    { if (yynerrs == 0 && semnerrs == 0) 
			{ 
				/*
					mac用
				emit("bits", "32", NULL, NULL);
				emit("section", ".text", NULL, NULL);
				*/
				emit_program((yyvsp[(2) - (2)].n));
				optimize();
		     	print_code();
		     }
		}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 93 "compiler.y"
    { (yyval.n) = make_tuple2(PRGM, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 97 "compiler.y"
    { (yyval.n) = make_tuple1(DECL, (yyvsp[(1) - (1)].n)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 102 "compiler.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 107 "compiler.y"
    { (yyval.n) = make_tuple2(DECLARATORL, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 111 "compiler.y"
    { (yyval.n) = make_decl((yyvsp[(1) - (1)].n)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 113 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, make_decl((yyvsp[(1) - (3)].n)), (yyvsp[(3) - (3)].n)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 120 "compiler.y"
    { make_fun_def((yyvsp[(2) - (3)].n)); cur_lev++; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 122 "compiler.y"
    { set_offset((yyvsp[(2) - (5)].n)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 124 "compiler.y"
    { (yyval.n) = make_tuple3(FUNDEF, (yyvsp[(2) - (8)].n), (yyvsp[(5) - (8)].n), (yyvsp[(8) - (8)].n));
			number_of_param = 0; pop(cur_lev); cur_lev--; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 129 "compiler.y"
    { (yyval.n) = NULL; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 135 "compiler.y"
    { (yyval.n) = make_tuple2(PARAMTYPEL, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 139 "compiler.y"
    { (yyval.n) = make_parm_decl((yyvsp[(2) - (2)].n)); number_of_param++; set_offset((yyval.n)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 143 "compiler.y"
    { (yyval.n) = NULL; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 145 "compiler.y"
    { (yyval.n) = make_tuple1(EXPR, (yyvsp[(1) - (2)].n)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 147 "compiler.y"
    { (yyval.n) = make_tuple1(CMPD_STM, (yyvsp[(1) - (1)].n)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 149 "compiler.y"
    { (yyval.n) = make_tuple2(IF, (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 151 "compiler.y"
    { (yyval.n) = make_tuple3(IF, (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(7) - (7)].n)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 153 "compiler.y"
    { in_loop = 1; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 155 "compiler.y"
    { (yyval.n) = make_tuple2(WHILE, (yyvsp[(4) - (6)].n), (yyvsp[(6) - (6)].n)); in_loop = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 157 "compiler.y"
    { in_loop = 1; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 159 "compiler.y"
    { (yyval.n) = make_tuple(FOR, (yyvsp[(4) - (10)].n), (yyvsp[(6) - (10)].n), (yyvsp[(8) - (10)].n), (yyvsp[(10) - (10)].n)); in_loop = 0; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 161 "compiler.y"
    { (yyval.n) = make_tuple1(RETURN, (yyvsp[(2) - (3)].n)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 165 "compiler.y"
    { cur_lev++; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 167 "compiler.y"
    { (yyval.n) = make_tuple2(CONS, (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); pop(cur_lev); cur_lev--; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 171 "compiler.y"
    { (yyval.n) = NULL; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 176 "compiler.y"
    { (yyval.n) = NULL; }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 182 "compiler.y"
    { (yyval.n) = make_tuple2(DECLARATIONL, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 187 "compiler.y"
    { (yyval.n) = make_tuple2(STATEL, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 191 "compiler.y"
    { (yyval.n) = NULL; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 197 "compiler.y"
    { (yyval.n) = make_tuple2(CONS, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 199 "compiler.y"
    { check_break(); (yyval.n) = make_tuple1(BREAK, NULL); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 201 "compiler.y"
    { check_continue(); (yyval.n) = make_tuple1(CONTINUE, NULL); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 206 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 208 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, (yyvsp[(1) - (3)].n), make_tuple2(PLUS, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n))); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 210 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, (yyvsp[(1) - (3)].n), make_tuple2(MINUS, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n))); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 212 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, (yyvsp[(1) - (3)].n), make_tuple2(TIMES, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n))); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 214 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, (yyvsp[(1) - (3)].n), make_tuple2(DIV, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n))); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 216 "compiler.y"
    { (yyval.n) = make_tuple2(ASSIGN, (yyvsp[(1) - (3)].n), make_tuple2(REMAIN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n))); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 221 "compiler.y"
    { (yyval.n) = make_tuple2(OR, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 226 "compiler.y"
    { (yyval.n) = make_tuple2(AND, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 231 "compiler.y"
    { (yyval.n) = make_tuple2(EQ, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 233 "compiler.y"
    { (yyval.n) = make_tuple2(NE, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 238 "compiler.y"
    { (yyval.n) = make_tuple2(LT, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 240 "compiler.y"
    { (yyval.n) = make_tuple2(MT, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 242 "compiler.y"
    { (yyval.n) = make_tuple2(ELT, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 244 "compiler.y"
    { (yyval.n) = make_tuple2(EMT, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 249 "compiler.y"
    { (yyval.n) = make_tuple2(PLUS, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 251 "compiler.y"
    { (yyval.n) = make_tuple2(MINUS, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 256 "compiler.y"
    { (yyval.n) = make_tuple2(TIMES, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 258 "compiler.y"
    { (yyval.n) = make_tuple2(DIV, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 260 "compiler.y"
    { (yyval.n) = make_tuple2(REMAIN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 265 "compiler.y"
    { (yyval.n) = make_tuple1(NEG, (yyvsp[(2) - (2)].n)); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 267 "compiler.y"
    { (yyval.n) = make_tuple1(INC, ref_var((yyvsp[(2) - (2)].n))); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 269 "compiler.y"
    { (yyval.n) = make_tuple1(DEC, ref_var((yyvsp[(2) - (2)].n))); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 274 "compiler.y"
    { (yyval.n) = make_tuple2(FCALL, ref_fun((yyvsp[(1) - (4)].n)), (yyvsp[(3) - (4)].n)); chkarg((yyval.n)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 278 "compiler.y"
    { (yyval.n) = NULL; }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 283 "compiler.y"
    { (yyval.n) = ref_var((yyvsp[(1) - (1)].n)); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 285 "compiler.y"
    { (yyval.n) = make_constant_node((yyvsp[(1) - (1)].i)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 287 "compiler.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 292 "compiler.y"
    { (yyval.n) = make_tuple2(ARGUEXPRL, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;



/* Line 1806 of yacc.c  */
#line 1998 "compiler.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 295 "compiler.y"

int yyerror(char *s){
	fprintf(stderr,  "%d: %s\n",  yylineno,  s);
	return 0;
}
int main(int argc, char *argv[]){
	// 引数なしの場合、標準入力から受け付け、標準出力へ出力する
	if(argc == 1) {
		 yyparse();
	// 1つ目の引数を入力ファイル名と見なす
	}else if(argc  > 1){
		if(yyin = fopen(argv[1], "r")) {
			// 引数が1つの場合、出力ファイル名は所定のものに
			if(argc == 2){
				char outfile[MAX], *p;
				sprintf(outfile, "%s", argv[1]);
				if((p = strrchr(outfile, '.')) != NULL){
					*p = '\0';		// 拡張子の削除
				}
				strcat(outfile, ".asm");
				if(yyout = fopen(outfile, "w")){
					yyparse();
					fclose(yyin);
					fclose(yyout);
				}else{
					printf("error: cannot open output file.\n");
					exit(-1);	
				}
			}else{
				if(yyout = fopen(argv[2], "w")){
					yyparse();
					fclose(yyin);
					fclose(yyout);
				}else{
					printf("error: cannot open output file.\n");
					exit(-1);	
				}
			}
		}else{
       		printf("error: cannot open input file.\n");
       		exit(-1);	
       	}
	}
    return 0;
}

