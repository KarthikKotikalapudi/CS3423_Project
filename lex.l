%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
\(	{/*printf("%s",yytext);*/  return OBRAC;}
\)	{/*printf("%s",yytext);*/  return CBRAC;}
\.	{/*printf("%s",yytext);*/  return DOT;}
!	{/*printf("%s",yytext);*/  return NEG;}
int|char|float|string|void|bool   { //printf("Datatype: %s\n", yytext);
                                return DATATYPE; }
matrix                          {return MATRIX;}
dataframe                       {return DF;}
":" {return COLON;}
";" {return SEMICOLON;}



[-]?[0-9]+ {return  INTEGER;} 
[-]?([0-9]*[.])?[0-9]+ {return FLOAT;}




(\")([^\"]|\\.)*(\")   {
                        yylval.str = strdup(yytext); 
                        return STRING;
                       }
'[^'\n]?' {
    yylval.character = yytext[1]; 
    return CHAR;
}
"++"|"--"	{/*printf("%s",yytext);*/  return POST;}
"<<"|">>"	{/*printf("%s",yytext);*/  return SHIFT;}
"**"|"%"|"*"|"/"|"+"|"-"	{/*printf("%s",yytext);*/  return ARTH;}
"<="|">="|"=="|"<"|">"	{/*printf("%s",yytext);*/  return COMP;}
"AND"|"OR"	{/*printf("%s",yytext);*/  return LOG;}
"="|"+="|"*="|"-="|"%="	{/*printf("%s",yytext);*/  return ASSGN;}


"<int>"|"<float>" {/*printf("%s",yytext);*/  return MATRIX_TYPE;}
"^"|"&"|"|"|  {/*printf("%s",yytext);*/  return BIT_OP;}

"break" {return BREAK;}
"continue" {return CONTINUE;}
"if" {return IF;}
"elif" {return ELIF;}
"ELSE" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"return" {return RETURN;}

#.*|#\*.*\*# {return COMMENTS;}



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
