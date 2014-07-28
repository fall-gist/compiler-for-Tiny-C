/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     RETURN = 264,
     PLUS = 265,
     MINUS = 266,
     TIMES = 267,
     DIV = 268,
     ASSIGN = 269,
     OR = 270,
     AND = 271,
     EQ = 272,
     NE = 273,
     LT = 274,
     MT = 275,
     ELT = 276,
     EMT = 277,
     NEG = 278,
     CONS = 279,
     PRGM = 280,
     DECL = 281,
     FUNDEF = 282,
     PARAM_DECL = 283,
     CMPD_STM = 284,
     EXPR = 285,
     FCALL = 286,
     DECLARATIONL = 287,
     DECLARATORL = 288,
     STATEL = 289,
     PARAMTYPEL = 290,
     ARGUEXPRL = 291
   };
#endif
/* Tokens.  */
#define CONST 258
#define IDENTIFIER 259
#define INT 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define RETURN 264
#define PLUS 265
#define MINUS 266
#define TIMES 267
#define DIV 268
#define ASSIGN 269
#define OR 270
#define AND 271
#define EQ 272
#define NE 273
#define LT 274
#define MT 275
#define ELT 276
#define EMT 277
#define NEG 278
#define CONS 279
#define PRGM 280
#define DECL 281
#define FUNDEF 282
#define PARAM_DECL 283
#define CMPD_STM 284
#define EXPR 285
#define FCALL 286
#define DECLARATIONL 287
#define DECLARATORL 288
#define STATEL 289
#define PARAMTYPEL 290
#define ARGUEXPRL 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 54 "tree.y"
{
	int i;
	char *str;
	tree n;
}
/* Line 1529 of yacc.c.  */
#line 127 "tree.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

