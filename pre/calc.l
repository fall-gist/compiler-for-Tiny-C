%option	noyywrap
%{
int yylval;
%}
digit		[0-9]
%%
{digit}+	{
				yylval = atoi(yytext);
				printf("INT = %d\n", yylval);
			}
"+"|"*"		{
				printf("ORP = %s\n", yytext);
			}
[ \t\n]	; /* スペース、タブ、改行は無視 */
.			;
%%
main()
{
	yylex();
}