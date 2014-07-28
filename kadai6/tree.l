%option noyywrap
%option yylineno

%{
#include<string.h>
#include "prints.h"
#include "tree.tab.h"
%}
digit		[0-9]
alpha		[a-zA-Z]
char		[a-zA-Z0-9_]
%%
int						return INT;
if						return IF;
else					return ELSE;
while					return WHILE;
return				return RETURN;
{digit}+				{
							yylval.i = atoi(yytext);
							return CONST;
						}
{alpha}{char}*		{
							yylval.str = strdup(yytext);
							return IDENTIFIER;
						}
"+"						return PLUS;
"-"						return MINUS;
"*"						return TIMES;
"/"						return DIV;
"="						return ASSIGN;
"||"					return OR;
"&&"					return AND;
"=="					return EQ;
"!="					return NE;
"<"						return LT;
">"						return MT;
"<="					return ELT;
">="					return EMT;

"("						return *yytext;
")"						return *yytext;
"{"						return *yytext;
"}"						return *yytext;
","						return *yytext;
";"						return *yytext;
[ \t\n]				;
.						yyerror("Error: invalid charcter");
%%

