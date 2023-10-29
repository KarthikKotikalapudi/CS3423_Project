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
%token NUM FLOAT DATATYPE MATRIX DF IF ELIF ELSE RETURN BREAK CONT ID OBRAK CBRAK OSQA CSQA OBRACE CBRACE DOT NEG COL SEMICOL  POST
%token COMMA STRING CHAR SHIFT COMP LOG ASSGN ARTHASSGN MATRIX_TYPE BIT_OP FOR WHILE PRINT MAIN
%left NEG LOG ARTH
%%
S : Decl Main Decl {}  // a valid program is sequence of declarations, functions
  ;

Decl : /* empty */
  | GlobalDecl Decl{} // a global variable declaration
  | FuncDecl Decl // function declaration
  ;

Main: MAIN OBRACE stmt CBRACE

GlobalDecl : declstmt {}
   ;

// stmt rule produces all possible sequence of statements with scopes in between 
stmt : stmtL OBRACE stmt CBRACE stmt {} // modify this if needed
    | stmtL {}
    ;

stmtL : stmtD stmtL {}
    | {}
    ;  

// these are different types of single statements
stmtD : declstmt 
    | exprstmt
    | callstmt
    | condstmt
    | loop
    | returnstmt
    | printstmt
    | break
    | continue
    ;


// declaration statment      
declstmt : DATATYPE IDL SEMICOL {}
    | DATATYPE ARRL SEMICOL {}
    | DATATYPE ID ASSGN rhs SEMICOL {}
    | DATATYPE ID OSQA CSQA ASSGN OBRACE constL CBRACE SEMICOL  {}
    | DATATYPE ID OSQA CSQA ASSGN OBRACE CBRACE SEMICOL  {}
    | MatrixDecl
    ;
        
IDL : ID COMMA IDL {}
    | ID {}
    ;

ARRL : ID OSQA arg CSQA COMMA ARRL {}
    | ID OSQA arg CSQA {}
    ;

constL : NUM COMMA constL {}
    | FLOAT COMMA constL {}
    | STRING COMMA constL {}
    | CHAR COMMA constL {}
    | NUM
    | FLOAT
    | STRING
    | CHAR
    ;

MatrixDecl : MATRIX ID MATRIX_TYPE SEMICOL {}
    | MATRIX ID MATRIX_TYPE ASSGN ID SEMICOL {}
    | MATRIX ID MATRIX_TYPE OBRAK numL CBRAK SEMICOL {}
    | MATRIX ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE SEMICOL {}
    ;

numL : NUM COMMA numL
    | NUM
    ;

MatrixL : OBRACE constL CBRACE MatrixL
    | OBRACE constL CBRACE
    ;

//function declaration
FuncDecl : FuncHead OBRAK params CBRAK OBRACE FuncBody CBRACE
    | 
    ;

FuncHead : DATATYPE ID
    ;

params : parameter COMMA params
    | parameter
    ;

parameter : DATATYPE ID
    | MATRIX MATRIX_TYPE ID
    | DATATYPE ID OSQA NUM CSQA
    ;

FuncBody : stmt
    ;

varL: arg 
    | varL COMMA arg
    ;

call_expression: ID OBRAK varL CBRAK
    | ID OBRAK CBRAK
    ;

callstmt: call_expression SEMICOL
    ;

// expression statments    
rhs : pred {}
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
      | arg SHIFT arg
      | arg BIT_OP arg 
      ;

arg : ID {} 
    | bin {} 
    | uni {}
    | call_expression {}
    | NUM 
    | FLOAT
    | ID OSQA arg CSQA
    ;

uni : ID POST
    | ID OSQA arg CSQA POST
    ;

bin : arg ARTH arg 
    ;

expr : ID ASSGN rhs {}
    | ID ARTHASSGN rhs {}
    | ID OSQA arg CSQA ASSGN rhs {}
    | ID OSQA arg CSQA ARTHASSGN rhs {}
    ;

exprstmt : expr SEMICOL
    ;

// conditional statement
condstmt : IF OBRAK pred CBRAK OBRACE stmt CBRACE  elif_list
    | IF OBRAK pred CBRAK OBRACE stmt CBRACE elif_list  ELSE OBRACE stmt CBRACE
    ;

elif_list : /* empty */
    | elif_list ELIF OBRAK pred CBRAK OBRACE stmt CBRACE
    ;
            
// loop statements
loop : FOR OBRAK declstmt  pred SEMICOL expr CBRAK OBRACE stmt CBRACE
    | FOR OBRAK declstmt  pred SEMICOL  CBRAK  OBRACE stmt CBRACE
    | FOR OBRAK   SEMICOL pred SEMICOL expr CBRAK  OBRACE stmt CBRACE
    | FOR OBRAK   SEMICOL pred SEMICOL  CBRAK  OBRACE stmt CBRACE
    | WHILE OBRAK pred CBRAK  OBRACE stmt CBRACE
    ;

break:
  BREAK SEMICOL
  ;

continue:
  CONT SEMICOL
  ;  

// return statement
returnstmt : RETURN pred SEMICOL
    ;

// print statement
printstmt : PRINT OBRAK STRING CBRAK SEMICOL

%%
//inbuilt functions
//create a dataframe
DF_DECL: DF ID ASSGN DF OBRAK CBRAK SEMICOL
        ;

//read a dataframe
DF_READ: ID DOT ID OBRAK ID COMMA ID CBRAK SEMICOL
       | ID DOT ID OBRAK ID COMMA ID COMMA STRING CBRAK SEMICOL
       ;
//assign a dataframe 
DF_ASSIGN : ID ASSGN ID DOT ID OBRAK ID CBRAK SEMICOL
          | ID ASSGN ID SEMICOL
          :
//GET COLUMN NAMES OF A DF
DF_GETCOL : ID ASSGN ID DOT ID OBRAK CBRAK SEMICOL
          ;

//ADD AND DROP COLUMNS
DF_ADDCOL : ID DOT ID OBRAK ID COMMA ID CBRAK SEMICOL
DF_DROPCOL: ID DOT ID OBRAK ID CBRAK SEMICOL

//ADD AND DELETE ROWS
DF_ADDROW : ID DOT ID OBRAK LIST CBRAK SEMICOL
          ;
LIST : LIST_ID COMMA LIST
     | LIST_ID
     ;
    
LIST_ID : ID
        | NULL
        | CONST
        ;

CONST   : NUM
        | CHAR
        | BOOL
        | STRING
        ;

DF_DELETEROW : 

//DESCRIBE DATAFRAME

DF_DESCRIBE : ID DOT ID OBRAK CBRAK SEMICOL

//WRITE A DATAFRAME 
DF_WRITE : ID DOT ID OBRAK ID COMMA ID COMMA ID CBRAK SEMICOL
         | ID DOT ID OBRAK ID COMMA ID CBRAK SEMICOL
         ;
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
    // if(!sq)
    // {
    //     printf("There was an error opening the output token file\n");
    //     return 0;
    // }
   yyparse();
   fclose(out); 
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    //fprintf(fp," : invalid statement");
}