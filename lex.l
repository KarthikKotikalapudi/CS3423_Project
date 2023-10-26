%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}
digit [0-9]
alpha [A-Za-z_]
%%
[-]?alpha+ {return  INTEGER;} 
[-]?(alpha*[.])?alpha+ {return FLOAT;}

#.*\n  /*ignoring one line comments*/
#\*(.|\n)*\*# /*ignoring multiline comments*/
int|char|float|string|void|bool   { //printf("Datatype: %s\n", yytext);
                                return DATATYPE; }
matrix                          {return MATRIX;}
dataframe                       {return DF;}


if {return IF;}
elif {return ELIF;}
else {return ELSE;}
return {return RETURN;}
break {return BREAK;}
continue {return CONT;}
alpha+(digit|alpha)* {return ID;}


\(	{/*printf("%s",yytext);*/  return OBRACK;}
\)	{/*printf("%s",yytext);*/  return CBRACK;}
\[  {/*printf("%s",yytext);*/  return OSQA;}
\]  {/*printf("%s",yytext);*/  return CSQA;}
\{  {/*printf("%s",yytext);*/  return OBRACE;}
\}  {/*printf("%s",yytext);*/  return CBRACE;}

\.	{/*printf("%s",yytext);*/  return DOT;}
!	{/*printf("%s",yytext);*/  return NEG;}


":" {return COLON;}
";" {return SEMICOLON;}
"," {return COMMA;}



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
