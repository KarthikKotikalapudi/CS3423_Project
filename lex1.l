%{
#include <stdio.h>
%}

%%
int|char|float|string|void   { printf("Datatype: %s\n", yytext); return Dtype; }

#*     {printf("Inline comments\n";)}
#\*[^#]*\*#    {printf("Multiple line comments\n");} 
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
