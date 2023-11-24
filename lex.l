%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.tab.h"
bool mat = 0;
int inout = 0;
char* mat_id = NULL;
int mat_scope = 0;
int bscope = 0;
bool oldmat = 0;
bool func_p = 0;
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


if {fprintf(out,"%s",yytext); return IF;}
elif {fprintf(out,"else if"); return ELIF;}
else {fprintf(out,"%s",yytext); return ELSE;}
return {fprintf(out,"%s",yytext); return RETURN;}
break {fprintf(out,"%s",yytext); return BREAK;}
continue {fprintf(out,"%s",yytext); return CONT;}
for {fprintf(out,"%s",yytext); return FOR;}
while {fprintf(out,"%s",yytext); return WHILE;}
print {fprintf(out,"cout"); inout = 2; return PRINT;}
input {fprintf(out,"cin"); inout = 1; return INPUT;}
main {fprintf(out,"int main()"); return MAIN;}
sort {fprintf(out,"%s",yytext); return SORT;}



\(	{/*printf("%s",yytext);*/
    bscope++;
    if(!inout || bscope > 1) fprintf(out,"%s",yytext);
    else if(inout == 1) fprintf(out,">>");
    else    fprintf(out,"<<");
    return OBRAK;}
\)	{/*printf("%s",yytext);*/
    bscope--;
    if(inout){
        if(bscope > 0)  fprintf(out,")");
    }
    else    fprintf(out,"%s",yytext);
    if(mat_scope < 0){
        mat = 0;
        mat_scope = 0;
    }
    return CBRAK;}
\[  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return OSQA;}
\]  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return CSQA;}
\{  {/*printf("%s",yytext);*/  
    if(func_p){
        func_p = 0;
        mat = 0;
        oldmat = 0;
        mat_scope = 0;
        mat_id = NULL;
    }
    fprintf(out,"%s",yytext); 
    if(oldmat) mat_scope++;
    return OBRACE;}
\}  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext);
    if(oldmat) mat_scope--;
    return CBRACE;}

\.	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return DOT;}
!	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return NEG;}


":" {fprintf(out,"%s",yytext); return COL;}
";" {
        if(mat_id != NULL){
            fprintf(out,"%s",mat_id);
            mat_id = NULL;
        }
        fprintf(out,"%s",yytext);
        mat = 0; inout = 0;
        mat_scope = 0;
        oldmat = 0;
        return SEMICOL;
    }
"," {
    if(mat_scope == 0 && oldmat){
        mat = 1;
        oldmat = 0;
    }
    if(inout){
        if(bscope <= 1)  fprintf(out,"<<");
        else    fprintf(out,",");
    }
    else if(func_p){
        mat = 0;
        fprintf(out,"%s",yytext);
    }
    else if(mat && bscope)  fprintf(out,"%s",yytext);
    else if(!mat){
        fprintf(out,"%s",yytext);
    }
    else if(mat_scope != 0){
        fprintf(out,"%s",yytext);
    }
    else{
        if(mat_id != NULL)  fprintf(out,"%s",mat_id);
        fprintf(out,"; matrix");
    }
    return COMMA;}



(\")([^\"]|\\.)*(\")   {
                        yylval.name = strdup(yytext);
                        fprintf(out,"%s",yytext); return STRING;
                       }
'[^'\n]?' {
    // yylval.character = yytext[1]; 
    //printf("%s",yytext);
    fprintf(out,"%s",yytext); return CHAR;
}


"<int>"|"<float>" {yylval.type =strdup( yytext);
    if(mat_id)  fprintf(out,"%s%s",yytext,mat_id);
    else{
        fprintf(out,"%s",yytext);
        func_p = 1;
        mat = 0;
        mat_scope = 0;
    }
    mat_id = NULL;
    return MATRIX_TYPE;
    }
"true"|"false"  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return BOOL;}
"NULL"  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return NUL;}
"++"|"--"	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return POST;}
"<<"|">>"	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return SHIFT;}
"**"|"%"|"*"|"/"|"+"	{yylval.name = strdup(yytext);  fprintf(out,"%s",yytext); return ARTH;}
"-" {/*printf("%s\n",yytext);*/  fprintf(out,"%s",yytext); return MINUS;}
"<="|">="|"=="|"<"|">"	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return COMP;}
"AND"	{/*printf("%s",yytext);*/  fprintf(out,"&&"); return LOG;}
"OR"	{/*printf("%s",yytext);*/  fprintf(out,"||"); return LOG;}
"=" {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext);
    if(mat){
        oldmat = 1;
        mat = 0;
    }
    return ASSGN;}
"+="|"*="|"-="|"/="|"%="	{/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return ARTHASSGN;}
"^"|"&"|"|"  {/*printf("%s",yytext);*/  fprintf(out,"%s",yytext); return BIT_OP;}

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
    printf("Lexical error at line %d: invalid token: %s\n", yylineno, yytext);
    exit(1);
}
%%

int yywrap()
{
    return 1;
}