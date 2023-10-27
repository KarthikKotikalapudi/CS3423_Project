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
%token NUM FLOAT Datatype MATRIX DF IF ELIF ELSE RETURN BREAK CONT ID OBRAK CBRAK OSQA CSQA OBRACE CBRACE DOT NEG COL SEMICOL  POST
%token COMMA STRING CHAR SHIFT ARTH COMP LOG ASSGN MATRIX_TYPE BIT_OP FOR WHILE 
%left NEG  LOG
%%
S : D Main D {}  // a valid program is sequence of declarations with a main function
  |
  ;
D : D D {}   
  | GD {} // a global variable declaration
  |
  ;

Main: stmt


GD : declstmt {}
   ;

     ; 
argL : Datatype ID COMMA argL {}
     | Datatype ID {} 
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
      | callstmt
      ;


//declaration statment      
declstmt : Datatype IDL SEMICOL {fprintf(fp," : declaration statement ");}
        ;
IDL : ID COMMA IDL {}
    | ID {}
    ;

//call statement
varL: arg 
    | varL COMMA

call_expression: ID OBRAK varL CBRAK
callstmt: call_expression SEMICOL

//expression statments    
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
    | FLOAT
    ;

uni : ID POST
bin : arg ARTH arg 
expr : ID ASSGN rhs {}
exprstmt: expr SEMICOL

//conditional statement
cond_stmt: IF OBRAK pred CBRAK OBRACE stmt CBRACE 
         | IF OBRAK pred CBRAK OBRACE stmt CBRACE  elif_list
         | IF OBRAK pred CBRAK OBRACE stmt CBRACE elif_list  ELSE OBRACE stmt CBRACE

elif_list: | elif_list ELIF  OBRAK pred CBRAK OBRACE stmt CBRACE 
            
//loop statements
loop: FOR OBRAK declstmt  pred SEMICOL expr CBRAK OBRACE stmt CBRACE
    | FOR OBRAK declstmt  pred SEMICOL  CBRAK  OBRACE stmt CBRACE
    | FOR OBRAK   SEMICOL pred SEMICOL expr CBRAK  OBRACE stmt CBRACE
    | FOR OBRAK   SEMICOL pred SEMICOL  CBRAK  OBRACE stmt CBRACE
    | WHILE OBRAK pred CBRAK  OBRACE stmt CBRACE

//function declaration



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