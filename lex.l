%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
#.*\n  /*ignoring one line comments*/
#\*(.|\n)*\*# /*ignoring multiline comments*/
int|char|float|string|void   { //printf("Datatype: %s\n", yytext);
                                return DATATYPE; }
matrix                          {return MATRIX;}
dataframe                       {return DF;}
if {return IF;}
elif {return ELIF;}
else {return ELSE;}
return {return RETURN;}
break {return BREAK;}
continue {return CONT;}
\(	{/*printf("%s",yytext);*/  return OBRAC;}
\)	{/*printf("%s",yytext);*/  return CBRAC;}
\.	{/*printf("%s",yytext);*/  return DOT;}
!	{/*printf("%s",yytext);*/  return NEG;}
";" {return COLON;}
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
