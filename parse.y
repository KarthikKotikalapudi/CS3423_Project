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
%token COMMA STRING CHAR SHIFT COMP LOG ASSGN ARTHASSGN MATRIX_TYPE BIT_OP FOR WHILE PRINT MAIN CLASS PRIVATE PROTECTED PUBLIC INHERITS
%token BOOL NUL SORT 
%left NEG LOG ARTH
%%
S : Decl Main Decl {}  // a valid program is sequence of declarations, functions
  ;

Decl : /* empty */
  | GlobalDecl Decl{} // a global variable declaration
  | FuncDecl Decl // function declaration
  ;

Main: MAIN OBRACE stmt CBRACE

GlobalDecl : declstmt
           |  class_decl {}
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
declstmt : DATATYPE ID Multideclstmt SEMICOL {}
    | DATATYPE ID OSQA arg CSQA Multideclstmt SEMICOL {}
    | DATATYPE ID ASSGN rhs Multideclstmt SEMICOL {}
    | DATATYPE ID OSQA CSQA ASSGN OBRACE constL CBRACE Multideclstmt SEMICOL  {}
    | DATATYPE ID OSQA CSQA ASSGN OBRACE CBRACE Multideclstmt SEMICOL  {}
    | MatrixDecl MultiMatrixDecl SEMICOL {}
    | object_decl
    ;

Multideclstmt : COMMA ID Multideclstmt {}
    | COMMA ID OSQA arg CSQA Multideclstmt {}
    | COMMA ID ASSGN rhs Multideclstmt {}
    | COMMA ID OSQA CSQA ASSGN OBRACE constL CBRACE Multideclstmt {}
    | COMMA ID OSQA CSQA ASSGN OBRACE CBRACE Multideclstmt {}
    | /* empty */
    ;

constL : NUM COMMA constL {}
    | FLOAT COMMA constL {}
    | STRING COMMA constL {}
    | CHAR COMMA constL {}
    | NUM
    | FLOAT
    | STRING
    | CHAR
    | BOOL
    ;

MatrixDecl : MATRIX ID MATRIX_TYPE {}
    | MATRIX ID MATRIX_TYPE ASSGN ID{}
    | MATRIX ID MATRIX_TYPE OBRAK numL CBRAK{}
    | MATRIX ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE{}
    ;

MultiMatrixDecl : COMMA ID MATRIX_TYPE MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE MultiMatrixDecl {}
    | /* empty */
    ;

numL : NUM COMMA NUM
    ;

MatrixL : OBRACE constL CBRACE COMMA MatrixL
    | OBRACE constL CBRACE
    ;

//function declaration
FuncDecl :FuncHead OBRAK params CBRAK OBRACE FuncBody CBRACE 
    ;

FuncHead : DATATYPE ID
    | ID ID
    ;

params : parameter COMMA params
    | parameter
    ;

parameter : DATATYPE ID
    | MATRIX ID MATRIX_TYPE
    | DATATYPE ID OSQA NUM CSQA
    | ID ID
    | ID ID OSQA NUM CSQA
    ;

FuncBody : stmt
    ;

varL: rhs 
    | varL COMMA rhs
    ;

function_call:ID OBRAK varL CBRAK
    | ID OBRAK CBRAK
    ;

call_expression: function_call
    ;

callstmt: call_expression SEMICOL
        | class_arg SEMICOL
        | SORT_FUN
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

class_arg:
     ID DOT ID
    | ID DOT function_call
    ;
    

arg : ID {} 
    | bin {} 
    | uni {}
    | call_expression {}
    | NUM 
    | FLOAT
    | BOOL
    | CHAR
    | STRING
    | ID access
    | class_arg
    ;

access : OSQA arg CSQA OSQA arg CSQA {}
       | OSQA arg CSQA {}
       ;

uni : ID POST
    | ID access POST
    ;

bin : arg ARTH arg 
    ;

expr : ID ASSGN rhs {}
    | ID ARTHASSGN rhs {}
    | ID access ASSGN rhs {}
    | ID access ARTHASSGN rhs {}
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



//class related syntax

class_decl:  CLASS ID OBRACE class_body CBRACE SEMICOL
           | Inheritance SEMICOL
   ;



class_body:| class_body access_specifier section_body
   ;

access_specifier: PRIVATE COL                                                                                                       
              | PUBLIC COL 
              | PROTECTED COL
              |
              ;



section_body: declstmt
            | FuncDecl
            ;

object_decl : ID ID Multiobj SEMICOL
          | ID ID ASSGN function_call Multiobj SEMICOL
          | ID ID ASSGN ID Multiobj SEMICOL
          ;  

Multiobj : /* empty */
         | COMMA ID ID
         | COMMA ID ID ASSGN function_call
         | COMMA ID ID ASSGN ID
         ;

//Inheritance
Inheritance: CLASS ID INHERITS PARENT_LIST OBRACE class_body CBRACE 

PARENT_LIST:  access_specifier ID 
           | access_specifier ID COMMA PARENT_LIST

           
//SORT FUNC
SORT_FUN    : SORT OBRAK ID COMMA ID ARTH NUM CBRAK SEMICOL
            | SORT OBRAK ID COMMA ID ARTH NUM COMMA NUM CBRAK SEMICOL
            | SORT OBRAK ID COMMA ID ARTH ID COMMA NUM CBRAK SEMICOL
            | SORT OBRAK ID COMMA ID ARTH ID CBRAK SEMICOL
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

   if(!yyparse())
   {
     printf("The parsing was successful\n");
   }
   fclose(out); 
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    //fprintf(fp," : invalid statement");
}