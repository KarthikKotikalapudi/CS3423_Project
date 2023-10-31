%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
FILE * out; //output file
%}
digit [0-9]
alpha [A-Za-z_]
beta  [0-9A-Za-z_]

%%
[-]?{digit}+ {return  NUM;} 
[-]?({digit}*[.])?{digit}+ {return FLOAT;}

#.*\n  {yylineno++;}/*ignoring one line comments*/
#\*(.|\n)*\*# /*ignoring multiline comments*/ {int i = 0; while(yytext[i] != '\0'){
    if(yytext[i] == '\n')   yylineno++;
    i++;
}}
int|char|float|string|void|bool   { //printf("Datatype: %s\n", yytext);
                                return DATATYPE; }
matrix                          {return MATRIX;}
dataframe                       {return DF;}

select {return SELECT;}
delete {return DELETE;}
update {return UPDATE;}

if {return IF;}
elif {return ELIF;}
else {return ELSE;}
return {return RETURN;}
break {return BREAK;}
continue {return CONT;}
for {return FOR;}
while {return WHILE;}
print {return PRINT;}
main {return MAIN;}
sort {return SORT;}



\(	{/*printf("%s",yytext);*/  return OBRAK;}
\)	{/*printf("%s",yytext);*/  return CBRAK;}
\[  {/*printf("%s",yytext);*/  return OSQA;}
\]  {/*printf("%s",yytext);*/  return CSQA;}
\{  {/*printf("%s",yytext);*/  return OBRACE;}
\}  {/*printf("%s",yytext);*/  return CBRACE;}

\.	{/*printf("%s",yytext);*/  return DOT;}
!	{/*printf("%s",yytext);*/  return NEG;}


":" {return COL;}
";" {return SEMICOL;}
"," {return COMMA;}



(\")([^\"]|\\.)*(\")   {
                        // yylval.str = strdup(yytext); 
                        return STRING;
                       }
'[^'\n]?' {
    // yylval.character = yytext[1]; 
    //printf("%s",yytext);
    return CHAR;
}


"<int>"|"<float>" {/*printf("%s",yytext);*/  return MATRIX_TYPE;}
"true"|"false"  {/*printf("%s",yytext);*/  return BOOL;}
"NULL"  {/*printf("%s",yytext);*/  return NUL;}
"++"|"--"	{/*printf("%s",yytext);*/  return POST;}
"<<"|">>"	{/*printf("%s",yytext);*/  return SHIFT;}
"**"|"%"|"*"|"/"|"+"	{/*printf("%s\n",yytext);*/  return ARTH;}
"-" {/*printf("%s\n",yytext);*/  return MINUS;}
"<="|">="|"=="|"<"|">"	{/*printf("%s",yytext);*/  return COMP;}
"AND"|"OR"	{/*printf("%s",yytext);*/  return LOG;}
"=" {/*printf("%s",yytext);*/  return ASSGN;}
"+="|"*="|"-="|"/="|"%="	{/*printf("%s",yytext);*/  return ARTHASSGN;}
"^"|"&"|"|"|"~"  {/*printf("%s",yytext);*/  return BIT_OP;}

Private {return PRIVATE;}
Public {return PUBLIC;}
Protected { return PROTECTED;}
Class {return CLASS;}
Inherits {return INHERITS;}
{alpha}+({beta})* {return ID;}


[ \t]  { /*Ignore whitespace and tabs*/ }
\n      { yylineno++; }
.   {
    /*Error*/
    printf("Error at line %d: invalid token: %s\n", yylineno, yytext);
    exit(1);
}
%%

int yywrap()
{
    return 1;
}