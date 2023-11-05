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
    using namespace std;
//global variables
int scope = 0;
vector<symbol_table> var_list;
vector<string> params;
vector<unordered_map<string,symtab>> sym_table_list;
std::unordered_map<std::vector<std::vector<std::string>>,functab> func_table_list;
%}
%token NUM FLOAT  MATRIX DF IF ELIF ELSE RETURN BREAK CONT  OBRAK CBRAK OSQA CSQA OBRACE CBRACE  DOT NEG COL SEMICOL  POST
%token COMMA STRING CHAR ASSGN ARTHASSGN MATRIX_TYPE FOR WHILE PRINT MAIN CLASS PRIVATE PROTECTED PUBLIC INHERITS
%token BOOL NUL SORT SELECT UPDATE DELETE
%left NEG LOG ARTH BIT_OP SHIFT COMP COMMA MINUS
%union{
     struct D{
        char* name;
        char* type;
        int* dim;
        int dim_len;
        int level;
    } datatype;
    char* type;
    int dim_len;
         struct F{
        char* name;
        char* ret_type;
    } funcattr;
}

%token <type> DATATYPE
%type <type> parameter
%type <dim_len> access access2 access_assgn access_retn
%type <type> uni arg numbers
%token <datatype> ID 
%%
S : Decl Main Decl {}  // a valid program is sequence of declarations, functions
  ;

Decl : /* empty */
  | GlobalDecl Decl{} // a global variable declaration
  | FuncDecl Decl // function declaration
  ;

Main : MAIN OBRACE open_marker stmt closing_marker CBRACE 
    ;

open_marker :  {scope++;}
    ;

closing_marker : {
    delete_symtab_level(scope);
    scope--;}
    ;

GlobalDecl : declstmt
           |  class_decl {}
   ;

// stmt rule produces all possible sequence of statements with scopes in between 
stmt : stmtL OBRACE open_marker stmt closing_marker CBRACE  stmt {} // modify this if needed
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
declstmt : DATATYPE ID Multideclstmt SEMICOL
        {   
            symtab var = search_symtab($2.name,scope); //check this,can string be char * 
            if(var)
            {
            cout<<"Semantic Error: variable already declared before use\n";
            exit(1);
            } 
            insert_symtab($2.name,$1,{},scope);
            for(int i=0;i<var_list.size();i++){
                if(search_symtab(var_list[i].name,scope))
                {
                cout<<"Semantic Error: variable already declared before use\n";
                exit(1);
                }
                insert_symtab(var_list[i].name,$1,var_list[i].dim,scope);
            }
            var_list.clear();
        }
    | DATATYPE ID access Multideclstmt SEMICOL
        {   
            symbolTable s2;
            s2.name= $2.name;
            for(int i=0;i<$3;i++){
                s2.dim.push_back(-1);
            }
            var_list.push_back(s2);
            for(int i=0;i<var_list.size();i++){
                if(search_symtab(var_list[i].name,scope))
                {
                cout<<"Semantic Error: variable already declared before use\n";
                exit(1);
                }
                insert_symtab(var_list[i].name,$1,var_list[i].dim,scope);
            }
            var_list.clear();
        }
    | DATATYPE ID ASSGN rhs Multideclstmt SEMICOL 
        {   
            symtab var = search_symtab($2.name,scope); //check this,can string be char * 
            if(var)
            {
            cout<<"Semantic Error: variable already declared before use\n";
            exit(1);
            } 
            insert_symtab($2.name,$1,{},scope);
            for(int i=0;i<var_list.size();i++){
                if(search_symtab(var_list[i].name,scope))
                {
                cout<<"Semantic Error: variable already declared before use\n";
                exit(1);
                }
                insert_symtab(var_list[i].name,$1,var_list[i].dim,scope);
            }
            var_list.clear();
        }
    | DATATYPE ID access2 ASSGN MultiDimL Multideclstmt SEMICOL  
        {   
            symbolTable s2;
            s2.name= $2.name;
            for(int i=0;i<$3;i++){
                s2.dim.push_back(-1);
            }
            var_list.push_back(s2);
            for(int i=0;i<var_list.size();i++){
                if(search_symtab(var_list[i].name,scope))
                {
                cout<<"Semantic Error: variable already declared before use\n";
                exit(1);
                }
                insert_symtab(var_list[i].name,$1,var_list[i].dim,scope);
            }
            var_list.clear();
        }
    | MatrixDecl MultiMatrixDecl SEMICOL {}
    | object_decl
    | DF_DECL
    ;

Multideclstmt : COMMA ID Multideclstmt {
    symbolTable s2;
    s2.name= $2.name;
    var_list.push_back(s2);
}
    | COMMA ID access Multideclstmt {
        symbolTable s2;
        s2.name= $2.name;
        for(int i=0;i<$3;i++){
            s2.dim.push_back(-1);
        }
        var_list.push_back(s2);
    }
    | COMMA ID ASSGN rhs Multideclstmt {
        symbolTable s2;
        s2.name= $2.name;
        var_list.push_back(s2);
    }
    | COMMA ID access2 ASSGN MultiDimL Multideclstmt {
        symbolTable s2;
        s2.name= $2.name;
        for(int i=0;i<$3;i++){
            s2.dim.push_back(-1);
        }
        var_list.push_back(s2);
    }
    | /* empty */
    ;

numbers : NUM {
          $$ = "int";
       }
     | MINUS NUM {
          $$ = "int";
     }
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


MultiDimL : OBRACE open_marker MultiDimL closing_marker CBRACE 
    | MultiDimL COMMA MultiDimL
    | OBRACE open_marker constL closing_marker CBRACE 
    ;

MatrixDecl : MATRIX ID MATRIX_TYPE {}
    | MATRIX ID MATRIX_TYPE ASSGN ID{}
    | MATRIX ID MATRIX_TYPE OBRAK numL CBRAK{}
    | MATRIX ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE {}
    ;

MultiMatrixDecl : COMMA ID MATRIX_TYPE MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE  MultiMatrixDecl {}
    | /* empty */
    ;

numL : numbers COMMA numbers
    ;

MatrixL : OBRACE open_marker constL closing_marker CBRACE  COMMA MatrixL
    | OBRACE open_marker constL closing_marker CBRACE 
    ;

//function declaration
FuncDecl :FuncHead OBRAK params CBRAK OBRACE open_marker FuncBody closing_marker CBRACE  
{
    //search if this function already exists

    //inserting function to function table
    insert_functab($1.name,params,$1.ret_type);
    params.clear();
}
    ;

FuncHead : DATATYPE ID {$$.name = $2; $$.ret_type = $1;}
    | ID ID
    | MATRIX MATRIX_TYPE ID
    | DF ID
    | DATATYPE access_retn ID
    | ID access_retn ID
    ;

params : parameter COMMA params {params.push_back($1);}
    | parameter {params.push_back($1);}
    ;

parameter : DATATYPE ID 
{ // sending datatypes for onserting function
   $$ = $1;
 // check if same name is used for different parameters
}
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
    

arg : ID { //use after declaration check
        symtab var = search_symtab($1.name,scope); //check this,can string be char * 
        if(!var)
        {
           cout<<"Semantic Error: A variable must be declared before use\n";
           exit(1);
        } 
        $$ = var.type;
        }
    | uni {$$ = $1;}
    | call_expression {}
    | numbers {
        //arg gets its attribute from child numbers
        $$ = $1;
    }
    | FLOAT {
        $$ = "float";
    }
    | BOOL{
        $$ = "bool";
    }
    | CHAR{
        $$ = "char";
    } 
    | STRING{
        $$ = "string";
    }
    | ID access{  symtab s;
       if((s=search_symtab($1.name,scope))){
      
           if($2 == s->dim.size()){
                   $$ = s->type;
           }
           else{
               cout<<"Semantic error: dimensions do not match\n";
               exit(1);
           }
        }
      else{
        //error
        cout<<"Semantic Error: A variable must be declared before use\n";
        exit(1);
      }
    }
    | class_arg
    ;

access : OSQA pred CSQA access {
    $$ = $4 +1;
}
       | OSQA pred CSQA {}
       {
        $$ =1;
       }
       ;

access_assgn :
        OSQA CSQA access
        {
            $$ = $3+1;
        }
        | OSQA CSQA {
            $$ = 1;
        }
       ;

access2 : access {$$ = $1;}
        | access_assgn {$$ =$1;}
        ;

access_retn : OSQA CSQA access_retn{ $$ = $3+1;}
        | OSQA CSQA {$$ = 1;}
       ;
       
uni : ID POST {
      symtab s;
       if((s=search_symtab($1.name,scope))){
           $$ = s->type;
        }
      else{
        //error
        cout<<"Semantic Error: A variable must be declared before use\n";
        exit(1);
      }
    }
    | ID access POST{
      symtab s;
       if((s=search_symtab($1.name,scope))){
      
           if($2 == s->dim.size()){
                   $$ = s->type;
           }
           else{
               cout<<"Semantic error: dimensions do not match\n";
               exit(1);
           }
        }
      else{
        //error
        cout<<"Semantic Error: A variable must be declared before use\n";
        exit(1);
      }
    }
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
condstmt : IF OBRAK pred CBRAK OBRACE open_marker stmt closing_marker CBRACE   elif_list
    | IF OBRAK pred CBRAK OBRACE open_marker stmt closing_marker CBRACE  elif_list  ELSE OBRACE open_marker stmt closing_marker CBRACE 
    ;

elif_list : /* empty */
    | elif_list ELIF OBRAK pred CBRAK OBRACE open_marker stmt closing_marker CBRACE 
    ;
            
// loop statements
loop : FOR OBRAK declstmt  pred SEMICOL expr CBRAK OBRACE open_marker stmt closing_marker CBRACE 
    | FOR OBRAK declstmt  pred SEMICOL  CBRAK  OBRACE open_marker stmt closing_marker CBRACE 
    | FOR OBRAK   SEMICOL pred SEMICOL expr CBRAK  OBRACE open_marker stmt closing_marker CBRACE 
    | FOR OBRAK   SEMICOL pred SEMICOL  CBRAK  OBRACE open_marker stmt closing_marker CBRACE 
    | WHILE OBRAK pred CBRAK  OBRACE open_marker stmt closing_marker CBRACE 
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

class_decl:  CLASS ID OBRACE class_body CBRACE  SEMICOL
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