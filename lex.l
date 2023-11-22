%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.tab.hpp"
bool mat = 0;
char* mat_id = NULL;
int mat_scope = 0;
FILE * out; //output file
%}
digit [0-9]
alpha [A-Za-z_]
beta  [0-9A-Za-z_]

%%
{digit}+ {yylval.val = atoi(yytext); fprintf(out,"%s",yytext); return NUM;} 
({digit}*[.])?{digit}+ {fprintf(out,"%s",yytext); return FLOAT;}

#.*\n  {yylineno++;}/*ignoring one line comments*/
#\*(.|\n)*\*# /*ignoring multiline comments*/ {int i = 0; while(yytext[i] != '\0'){
    if(yytext[i] == '\n')   yylineno++;
    i++;
}}
int|char|float|string|bool   { //printf("Datatype: %s\n", yytext);
                                yylval.type = strdup(yytext); 
                                fprintf(out,"%s",yytext); return DATATYPE; }
matrix                          {fprintf(out,"%s",yytext); mat = 1; return MATRIX;}
dataframe                       {fprintf(out,"%s",yytext); return DF;}
void                            {fprintf(out,"%s",yytext); return VOID;}

select {fprintf(out,"%s",yytext); return SELECT;}
delete {fprintf(out,"%s",yytext); return DELETE;}
update {fprintf(out,"%s",yytext); return UPDATE;}

if {fprintf(out,"%s",yytext); return IF;}
elif {fprintf(out,"%s",yytext); return ELIF;}
else {fprintf(out,"%s",yytext); return ELSE;}
return {fprintf(out,"%s",yytext); return RETURN;}
break {fprintf(out,"%s",yytext); return BREAK;}
continue {fprintf(out,"%s",yytext); return CONT;}
for {fprintf(out,"%s",yytext); return FOR;}
while {fprintf(out,"%s",yytext); return WHILE;}
print {fprintf(out,"%s",yytext); return PRINT;}
main {fprintf(out,"int main()"); return MAIN;}
sort {fprintf(out,"%s",yytext); return SORT;}



\(	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext);
    if(mat) mat_scope++;
    return OBRAK;}
\)	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext);
    if(mat) mat_scope--;
    return CBRAK;}
\[  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return OSQA;}
\]  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return CSQA;}
\{  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); 
    if(mat) mat_scope++;
    return OBRACE;}
\}  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext);
    if(mat) mat_scope--;
    return CBRACE;}

\.	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return DOT;}
!	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return NEG;}


":" {fprintf(out,"%s",yytext); return COL;}
";" {
        if(mat_id != NULL)  fprintf(out,"%s",mat_id);
        fprintf(out,"%s",yytext);
        mat = 0; return SEMICOL;
    }
"," {
    if(!(mat && mat_scope == 0))    fprintf(out,"%s",yytext);
    else{
        if(mat_id != NULL)  fprintf(out,"%s",mat_id);
        fprintf(out,"; matrix");
    }
    return COMMA;}



(\")([^\"]|\\.)*(\")   {
                        // yylval.str = 
                        fprintf(out,"%s",yytext); return STRING;
                       }
'[^'\n]?' {
    // yylval.character = yytext[1]; 
    //printf("%s",yytext);
    fprintf(out,"%s",yytext); return CHAR;
}


"<int>"|"<float>" {yylval.type =strdup( yytext); fprintf(out,"%s%s",yytext,mat_id); mat_id = NULL; return MATRIX_TYPE;}
"true"|"false"  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return BOOL;}
"NULL"  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return NUL;}
"++"|"--"	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return POST;}
"<<"|">>"	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return SHIFT;}
"**"|"%"|"*"|"/"|"+"	{/*printf("%s\n",yytext);*/  fprintf(out,"%s",yytext); return ARTH;}
"-" {/*printf("%s\n",yytext);*/  fprintf(out,"%s",yytext); return MINUS;}
"<="|">="|"=="|"<"|">"	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return COMP;}
"AND"	{/*printf("%s",yytext);*/  fprintf(out,"&&"); return LOG;}
"OR"	{/*printf("%s",yytext);*/  fprintf(out,"||"); return LOG;}
"=" {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext);
    return ASSGN;}
"+="|"*="|"-="|"/="|"%="	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return ARTHASSGN;}
"^"|"&"|"|"|"~"  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return BIT_OP;}

Private {fprintf(out,"private"); return PRIVATE;}
Public {fprintf(out,"public"); return PUBLIC;}
Protected { fprintf(out,"protected"); return PROTECTED;}
Class {fprintf(out,"class"); return CLASS;}
Inherits {fprintf(out," : "); return INHERITS;}
{alpha}+({beta})* { yylval.datatype.name = strdup(yytext);
    if(!mat) fprintf(out,"%s",yytext);
    else{
        mat_id = (char *)malloc(strlen(yytext) + 1);
        strcpy(mat_id,yytext);
    }
    return ID;}


[ \t]+  { /*Ignore whitespace and tabs*/ fprintf(out,"%s",yytext); }
\n      { yylineno++; fprintf(out,"\n"); }
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