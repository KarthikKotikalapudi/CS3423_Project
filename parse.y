%{
    #include"global.hpp"
    #include<bits/stdc++.h>
    #include "helper_functions.hpp"
    using namespace std;
    void yyerror(const char* s);
    extern int yylex(void);
    extern int yylineno;
    extern FILE* yyin;
    extern FILE* out;
//global variables
int scope = 0;
vector<symbol_table> var_list;
vector<unordered_map<string,symtab>> sym_table_list;
%}
%token NUM FLOAT  MATRIX DF IF ELIF ELSE RETURN BREAK CONT  OBRAK CBRAK OSQA CSQA OBRACE CBRACE DOT NEG COL SEMICOL  POST
%token COMMA STRING CHAR ASSGN ARTHASSGN MATRIX_TYPE FOR WHILE PRINT MAIN CLASS PRIVATE PROTECTED PUBLIC INHERITS
%token BOOL NUL SORT SELECT UPDATE DELETE
%left NEG LOG ARTH BIT_OP SHIFT COMP COMMA MINUS
%union{
     struct D{
        std::string name;
        std::string type;
        std::vector<int> dim;
        int level;
    } datatype;
    std::string type;
}

%token <type> DATATYPE
%token <datatype> ID
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
    | DATATYPE ID access Multideclstmt SEMICOL {    }
    | DATATYPE ID ASSGN rhs Multideclstmt SEMICOL {
        
    }
    | DATATYPE ID access2 ASSGN MultiDimL Multideclstmt SEMICOL  {}
    | MatrixDecl MultiMatrixDecl SEMICOL {}
    | object_decl
    | DF_DECL
    ;

Multideclstmt : COMMA ID Multideclstmt {
    var_
}
    | COMMA ID access Multideclstmt {
               
    }
    | COMMA ID ASSGN rhs Multideclstmt {}
    | COMMA ID access2 ASSGN MultiDimL Multideclstmt {}
    | /* empty */
    ;

numbers : NUM
     | MINUS NUM
     ;

constL : numbers COMMA constL {}
    | FLOAT COMMA constL {}
    | STRING COMMA constL {}
    | CHAR COMMA constL {}
    | numbers
    | FLOAT
    | STRING
    | CHAR
    | BOOL
    ;


MultiDimL : OBRACE MultiDimL CBRACE
    | MultiDimL COMMA MultiDimL
    | OBRACE constL CBRACE
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

numL : numbers COMMA numbers
    ;

MatrixL : OBRACE constL CBRACE COMMA MatrixL
    | OBRACE constL CBRACE
    ;

//function declaration
FuncDecl :FuncHead OBRAK params CBRAK OBRACE FuncBody CBRACE 
    ;

FuncHead : DATATYPE ID
    | ID ID
    | MATRIX MATRIX_TYPE ID
    | DF ID
    | DATATYPE access_retn ID
    | ID access_retn ID
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
    | DF_UPDATECOL
    | DF_SELECT
    | DF_DELETEROW
    ;

call_expression: function_call
    ;

callstmt: call_expression SEMICOL
        | class_arg SEMICOL
        | SORT_FUN
    ;

class_arg:
     ID DOT ID
    | ID DOT function_call
    ;

// expression statments    
rhs : pred {}
    ;

// pred rules produces all valid predicates
pred : pred LOG pred { } 
    | OBRAK pred CBRAK { }
    | NEG pred
    | arg { }
    | pred COMP pred { }
    | pred SHIFT pred { }
    | pred BIT_OP pred { }
    | pred ARTH pred { }
    | pred MINUS pred { }
    ;

// OP : LOG
//    | COMP
//    | SHIFT
//    | BIT_OP
//    | ARTH
//    ;

// // pred produces the basic elements of a general predicate
// predD : arg { } 
//       ;
    

arg : ID {}
    | uni {}
    | call_expression {}
    | numbers
    | FLOAT
    | BOOL
    | CHAR
    | STRING
    | ID access
    | class_arg
    ;

access : OSQA pred CSQA access
       | OSQA pred CSQA {}
       ;

access_assgn :
        OSQA CSQA access
        | OSQA CSQA {}
       ;

access2 : access 
        | access_assgn
        ;

access_retn : OSQA CSQA access_retn
        | OSQA CSQA {}
       ;
       
uni : ID POST
    | ID access POST
    ;

// bin : arg ARTH arg 
//     ;

expr : ID ASSGN rhs {}
    | ID ARTHASSGN rhs {}
    | ID access ASSGN rhs {}
    | ID access ARTHASSGN rhs {}
    | uni {}
    | ID DOT ID ASSGN rhs {}
    | ID DOT ID ARTHASSGN rhs {}
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
SORT_FUN    : SORT OBRAK rhs COMMA rhs CBRAK SEMICOL
            | SORT OBRAK rhs COMMA rhs COMMA MINUS NUM CBRAK SEMICOL
            ;

//decl, select, update, delete 

DF_DECL: DF ID ASSGN DF OBRAK CBRAK SEMICOL
        ;

DF_DELETEROW : DELETE OBRAK ID COMMA pred CBRAK
             ;
            
DF_UPDATECOL : UPDATE OBRAK ID COMMA ID COMMA pred COMMA rhs CBRAK
             | UPDATE OBRAK ID COMMA ID COMMA NUL COMMA rhs CBRAK
             ;

DF_SELECT   : SELECT OBRAK ID COMMA ID COMMA pred CBRAK
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