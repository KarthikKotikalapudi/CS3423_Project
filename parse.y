%{
    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    void yyerror(const char* s);
    extern int yylex(void);
    extern int yylineno;
    extern FILE* yyin;
    extern FILE* out;
%}
%token NUM FLOAT DTP MATRIX DF IF ELIF ELSE RETURN BREAK CONT ID OBRAK CBRAK OSQA CSQA OBRACE CBRACE DOT NEG COL SEMICOL 
%token COMMA STRING CHAR SHIFT ARTH COMP LOG ASSGN MATRIX_TYPE BIT_OP   
%left NEG  LOG
%%
S : D Main D {}  // a valid program is sequence of declarations with a main function
  |
  ;
D : D D {}   
  | GD {} // a global variable declaration
  | FD {} // a function declaration
  |
  ;
GD : declstmt {}
   ;
FD : sign LBR stmt RBR {}
   ;
sign : DTP  ID LPAR argL RPAR  {}
     ; 
argL : DTP ID COMMA argL {}
     | DTP ID {} 
     ;
// stmt rule produces all possible sequence of statements with scopes in between 
stmt : stmtL OBRAK stmt CBRAK stmt {} // modify this if needed
     | stmtL {}
     ;
stmtL : stmtD stmtL {}
      | {}
      ;  
// these are different types of single statements
stmtD : declstmt 
      | exprstmt
      ;



//declaration statment      
declstmt : DTP IDL SEMICOL {fprintf(fp," : declaration statement ");}
        ;
IDL : ID COMMA IDL {}
    | ID {}
    ;

//expression statments    
exprstmt : ID ASSGN rhs {}
rhs : pred {} // pred variable covers predicates and all types of other valid rhs elements
    ;
// pred rules produces all valid predicates
pred : pred LOG pred { } 
     | OBRAK pred CBRAK { }
     | NEG pred
     | predD { }
     ;
// pred produces the basic elements of a general predicate
predD : arg { } 
      | arg COMP arg { }

arg : ID {} 
    | bin {} 
    | uni {}
    | callstmt {}
    | NUM 
    | TF 
    | CNST 
    ;

   ;
%%

int main(int argc,char** argv)
{
    
    if(argc!= 2)
    {
        printf("provide command line arguments correctly\n");
        return 0;
    }
    FILE* inp = fopen(argv[1],"r");
    if(!inp)
    {
        printf("There was an error opening this input file\n");
        return 0;
    }
    yyin = inp;
    for(int i=0;i<strlen(argv[1]);i++)
    {
         if(argv[1][i]=='.')
         {
            argv[1][i] = '\0'; break;
         }
    }
    char tokf[50];
    snprintf(tokf,sizeof(tokf), "out_%s.txt", argv[1]);
    out = fopen(tokf,"w");   //opeing the output seq tokens file
    if(!sq)
    {
        printf("There was an error opening the output token file\n");
        return 0;
    }
   yyparse();
   fclose(out); 
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    fprintf(fp," : invalid statement");
}