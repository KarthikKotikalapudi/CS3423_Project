%{
#include <stdio.h>
%}

%%
\(	{/*printf("%s",yytext);*/  return OPENBRAC;}
\)	{/*printf("%s",yytext);*/  return CLOSEBRAC;}
\.	{/*printf("%s",yytext);*/  return DOT;}
!	{/*printf("%s",yytext);*/  return NEG;}
"++"|"--"	{/*printf("%s",yytext);*/  return POST;}
"<<"|">>"	{/*printf("%s",yytext);*/  return SHIFT;}
"**"|"%"|"*"|"/"|"+"|"-"	{/*printf("%s",yytext);*/  return ARTH;}
"<="|">="|"=="|"<"|">"	{/*printf("%s",yytext);*/  return COMP;}
"AND"|"OR"	{/*printf("%s",yytext);*/  return LOG;}
"="|"+="|"*="|"-="|"%="	{/*printf("%s",yytext);*/  return ASSGN;}
[ \t]  { /*Ignore whitespace and tabs*/ }
\n      { yylineno++; }
.   {
    /*Error*/
    printf("Error at line %d: invalid token: %s\n", yylineno, yytext);
    exit(1);
}
%%
int main(){
    yylex();
    return 0;
}
