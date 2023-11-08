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
vector<string> params; 
bool func = true;
classtab active_class_ptr = NULL;
string access_spec;
%}
%token NUM FLOAT  MATRIX DF IF ELIF ELSE RETURN BREAK CONT  OBRAK CBRAK OSQA CSQA OBRACE CBRACE  DOT NEG COL SEMICOL  POST
%token COMMA STRING CHAR ASSGN ARTHASSGN  FOR WHILE PRINT MAIN CLASS PRIVATE PROTECTED PUBLIC INHERITS
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
    const char* type;
    const char* name;
    int dim_len;
         struct F{
        char* name;
        char* ret_type;
    } funcattr;
    struct matrixdim{
        int row;
        int col;
    } MD;
    struct CONSTL{
        int len;
        char*name;
    }CL;
}

%token <type> DATATYPE MATRIX_TYPE
%type <type> parameter access_specifier
%type <dim_len> access access2 access_assgn access_retn
%type <type> uni arg numbers rhs pred
%type <name> function_call
%type <funcattr> FuncHead 
%token <datatype> ID 
%type <MD> numL MatrixL
%type <CL> constL
%%
S : Decl Main Decl {}  // a valid program is sequence of declarations, functions
  ;

Decl : /* empty */
  | GlobalDecl Decl{} // a global variable declaration
  | FuncDecl Decl // function declaration
  ;

Main : MAIN OBRACE open_marker stmt closing_marker CBRACE 
    ;

open_marker :  {scope++; func = false;}
    ;

closing_marker : {
    delete_symtab_level(scope);
    scope--; func=true;}
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
            if(active_class_ptr){
                pair<string,string> var = search_classvar($2.name,active_class_ptr->name); //check this,can string be char * 
                if(var.first != "")
                {
                cout<<"Semantic Error: variable already declared\n";
                exit(1);
                } 
                insert_classvar($2.name,$1,access_spec,active_class_ptr);
                for(int i=0;i<var_list.size();i++){
                    if(search_classvar(var_list[i].name,active_class_ptr->name).first!="")
                    {
                    cout<<"Semantic Error: variable already declared \n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr);
                }
                var_list.clear();
            }
            else{
                symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
                if(var)
                {
                cout<<"Semantic Error: variable already declared\n";
                exit(1);
                } 
                insert_symtab($2.name,$1,{},scope);
                for(int i=0;i<var_list.size();i++){
                    if(search_symtab(var_list[i].name,scope,func))
                    {
                    cout<<"Semantic Error: variable already declared \n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
                }
                var_list.clear();
            }
        }
    | DATATYPE ID access Multideclstmt SEMICOL
        {   
            symbolTable s2;
            s2.name= $2.name;
            for(int i=0;i<$3;i++){
                s2.dim.push_back(-1);
            }
            var_list.push_back(s2);
            if(active_class_ptr){
                for(int i=0;i<var_list.size();i++){
                    if(search_classvar(var_list[i].name,active_class_ptr->name).first!="")
                    {
                    cout<<"Semantic Error: variable already declared \n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr);
                }
                var_list.clear();
            }
            else{
                for(int i=0;i<var_list.size();i++){
                    if(search_symtab(var_list[i].name,scope,func))
                    {
                    cout<<"Semantic Error: variable already declared\n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
                }
                var_list.clear();
            }
        }
    | DATATYPE ID ASSGN rhs Multideclstmt SEMICOL 
        {   
            if(active_class_ptr){
                pair<string,string> var = search_classvar($2.name,active_class_ptr->name); //check this,can string be char * 
                if(var.first != "")
                {
                cout<<"Semantic Error: variable already declared\n";
                exit(1);
                }
                if($4!=$1){
                    cout<<"Semantic Error: Type Mismatch\n";
                    exit(1);
                } 
                insert_classvar($2.name,$1,access_spec,active_class_ptr);
                for(int i=0;i<var_list.size();i++){
                    if(search_classvar(var_list[i].name,active_class_ptr->name).first!="")
                    {
                    cout<<"Semantic Error: variable already declared \n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr);
                }
                var_list.clear();
            }
            else{
                symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
                if(var)
                {
                cout<<"Semantic Error: variable already declared\n";
                exit(1);
                } 
                if($4!=$1){
                    cout<<"Semantic Error: Type Mismatch\n";
                    exit(1);
                }
                insert_symtab($2.name,$1,{},scope);
                for(int i=0;i<var_list.size();i++){
                    if(search_symtab(var_list[i].name,scope,func))
                    {
                    cout<<"Semantic Error: variable already declared\n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
                }
                var_list.clear();
            }
        }
    | DATATYPE ID access2 ASSGN MultiDimL Multideclstmt SEMICOL  
        {   

            symbolTable s2;
            s2.name= $2.name;
            for(int i=0;i<$3;i++){
                s2.dim.push_back(-1);
            }
            var_list.push_back(s2);
            if(active_class_ptr){
                for(int i=0;i<var_list.size();i++){
                    if(search_classvar(var_list[i].name,active_class_ptr->name).first!="")
                    {
                    cout<<"Semantic Error: variable already declared \n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr);
                }
                var_list.clear();
            }
            else{
                for(int i=0;i<var_list.size();i++){
                    if(search_symtab(var_list[i].name,scope,func))
                    {
                    cout<<"Semantic Error: variable already declared\n";
                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
                }
                var_list.clear();
            }
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

constL : numbers COMMA constL { $$.len =   $3.len + 1;}
    | FLOAT COMMA constL {  $$.len = $3.len +1 ;}
    | STRING COMMA constL { $$.len = $3.len +1; }
    | CHAR COMMA constL { $$ = $3 +1 ;}
    | numbers {$$.len = 1;}
    | FLOAT { $$.len = 1;}
    | STRING {$$.len = 1;}
    | CHAR {$$.len = 1 ;}
    | BOOL {$$.len = 1;}
    ;


MultiDimL : OBRACE open_marker MultiDimL closing_marker CBRACE 
    | MultiDimL COMMA MultiDimL
    | OBRACE open_marker constL closing_marker CBRACE 
    ;

MatrixDecl : MATRIX ID MATRIX_TYPE {
         //first check if already declared
           symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared\n";
            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(strcmp(mtype,$3) || strcmp(mtype1,$3)){
            //add matrix with type int or float
            insert_symtab($2.name,$3,{},scope);
         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float\n";
         }

    }
    | MATRIX ID MATRIX_TYPE ASSGN ID{
        symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared\n";
            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(strcmp(mtype,$3) || strcmp(mtype1,$3)){
              //add matrix with type int or float
               insert_symtab($2.name,$3,{},scope);
            
               symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
              if(var)
               {
                //compare the rhs matrix type
                if(strcmp(var->type,$3)){
                    //do nothing
                }
                else{
                    cout<<"Semantic Error: Martices are of different types\n";
                }
               } 
               else{
                cout<<"Semantic Error: variable already declared\n";
                exit(1);
               }
         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float\n";
         }
    
    }
    | MATRIX ID MATRIX_TYPE OBRAK numL CBRAK{
             symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared\n";
            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(strcmp(mtype,$3) || strcmp(mtype1,$3)){
            //add matrix with type int or float
            // also patch the dimensions from numL
            insert_symtab($2.name,$3,{$5.row,$5.col},scope);
         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float\n";
         }

    }
    | MATRIX ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE {
                        symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared\n";
            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(strcmp(mtype,$3) || strcmp(mtype1,$3)){
            //add matrix with type int or float
            // also patch the dimensions from MAtrixL

            insert_symtab($2.name,$3,{$6.row,$6.col},scope);

         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float\n";
         }      

    }
    ;

MultiMatrixDecl : COMMA ID MATRIX_TYPE MultiMatrixDecl {
       //Assign type to ID , MultiMatrixDecl
}
    | COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl {}
    | COMMA ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE  MultiMatrixDecl {}
    | /* empty */
    ;

numL : numbers COMMA numbers {
            $$.row = $1;
            $$.col = $3;
      }
    ;

MatrixL : OBRACE open_marker constL closing_marker CBRACE  COMMA MatrixL {
                //get the dimesion from inner MatrixL and constL
                $$.row = $7.row + 1;
                if($7.col ! = $3.len){
                    cout<<"Intiliaztion of Matrix with jagged array is not allowed"<<endl;
                    exit(1);
                }
                $$.col = $3.len;
       }
    | OBRACE open_marker constL closing_marker CBRACE {
               //get the dimesion from constL
               $$.row = 1;
               $$.col = $3.len;
    }
    ;

//function declaration
FuncDecl :FuncHead OBRAK params CBRAK OBRACE open_marker FuncBody closing_marker CBRACE  
{
    //search if this function already exists
    if(search_functab($1.name,params))
    {
        cout<<"Semantic Error: function already declared\n";
        exit(1);
    }
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
 // checking if same name is used for different parameters
 symtab par = search_symtab($2.name,scope+1,func);
 if(par)
            {
            cout<<"Semantic Error: two parameters cannot have same name\n Parameter name "<<$2.name<<" is already used\n";
            exit(1);
            } 
}
    | MATRIX ID MATRIX_TYPE
    | DATATYPE ID OSQA CSQA {string dt = $1;
       dt = dt+"[]";
       char* temp = new char[dt.length()+1]; strcpy(temp,dt.c_str());
       $$ = temp;}
    | ID ID
    | ID ID OSQA CSQA
    ;

FuncBody : stmt
    ;

varL: rhs {params.push_back($1);}
    | rhs COMMA varL {params.push_back($1);}
    ;

function_call:ID OBRAK varL CBRAK  {$$ = $1.name;}
    | ID OBRAK CBRAK {$$ = $1.name;}
    | DF_UPDATECOL
    | DF_SELECT
    | DF_DELETEROW
    ;



callstmt: function_call SEMICOL {
     functab fun = search_function($1,params);
     if(!fun)
     {
            cout<<"Semantic Error: This function is not declared\n";
            error(1);
     }
     params.clear();
     }
        | class_arg SEMICOL
        | SORT_FUN
    ;

class_arg:
     ID DOT ID
    | ID DOT function_call
    ;

// expression statments    
rhs : pred { $$ = $1;}
    ;

// pred rules produces all valid predicates
pred : pred LOG pred 
        {
            $$ ="bool";
        }
    | OBRAK pred CBRAK { $$ = $2; }
    | NEG pred { $$ = "bool"; }
    | arg { $$ = $1; }
    | pred COMP pred 
    {
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Comparator operation must be same"<<endl;
            exit(1);
        }
        $$ = "bool";
    }
    | pred SHIFT pred 
    {
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Arthimatic operation must be coersible"<<endl;
            exit(1);
        }
        $$ = $1;
    }
    | pred BIT_OP pred 
    {
        if($1 != $3){
            cout<<"Semantic Error: Both sides of the Bitwise operation must be same"<<endl;
            exit(1);
        }
        $$ = $1;
    }
    | pred ARTH pred 
    {   
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Arthimatic operation must be coersible"<<endl;
            exit(1);
        }
        $$ = dominate($1,$3).c_str();
    }
    | pred MINUS pred 
    {   
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Arthimatic operation must be coersible"<<endl;
            exit(1);
        }
        $$ = dominate($1,$3).c_str();;
    }
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
        symtab var = search_symtab($1.name,scope,func); //check this,can string be char * 
        if(!var)
        {
           cout<<"Semantic Error: A variable must be declared before use\n";
           exit(1);
        } 
        $$ = var->type.c_str();
        }
    | uni {$$ = $1;}
    // | call_expression {}
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
       if((s=search_symtab($1.name,scope,func))){
      
           if($2 == s->dim.size()){
                   $$ = s->type.c_str();
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

access : OSQA pred CSQA access 
        {
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
       if((s=search_symtab($1.name,scope,func))){
           $$ = s->type.c_str();
        }
      else{
        //error
        cout<<"Semantic Error: A variable must be declared before use\n";
        exit(1);
      }
    }
    | ID access POST{
      symtab s;
       if((s=search_symtab($1.name,scope,func))){
      
           if($2 == s->dim.size()){
                   $$ = s->type.c_str();
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

expr : ID ASSGN rhs 
        {   symtab var;
            if((var=search_symtab($1.name,scope,func))){
                if(!coersible(var->type,$3)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use\n";
                exit(1);
            }
        }
    | ID ARTHASSGN rhs 
        {   symtab var;
            if((var=search_symtab($1.name,scope,func))){
                if(!coersible(var->type,$3)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use\n";
                exit(1);
            }
        }
    | ID access ASSGN rhs 
        {   
            symtab var;
            if((var=search_symtab($1.name,scope,func))){
                if(var->dim.size()!=$2){
                    cout<<"Semantic error: dimensions do not match\n";
                    exit(1);
                }
                if(!coersible(var->type,$4)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use\n";
                exit(1);
            }
        }
    | ID access ARTHASSGN rhs 
        {   symtab var;
            if((var=search_symtab($1.name,scope,func))){
                if(var->dim.size()!=$2){
                    cout<<"Semantic error: dimensions do not match\n";
                    exit(1);
                }
                if(!coersible(var->type,$4)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use\n";
                exit(1);
            }
        }
    | uni { }
    | ID DOT ID ASSGN rhs 
        {
            
        }
    | ID DOT ID ARTHASSGN rhs 
        {
            
        }
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
    ;



//class related syntax

class_decl:  class_head OBRACE class_body CBRACE  SEMICOL{active_class_ptr = NULL;}
   ;

class_head : CLASS ID{
        if(search_classtab($2.name)){
            cout<<"Semantic Error: Class already declared\n";
            exit(1);
        }
        pair<string,string> temp;
        insert_classtab($2.name,temp);
        active_class_ptr = search_classtab($2.name);
    }
    | CLASS ID INHERITS access_specifier ID{
        //Inheritance

        if(search_classtab($2.name)){
            cout<<"Semantic Error: Class already declared\n";
            exit(1);
        }
        pair<string,string> temp;
        temp.first = $4;
        temp.second = $2.name;
        insert_classtab($2.name,temp);
        active_class_ptr = search_classtab($2.name);
    }
    ;

class_body:
    | section_body class_body
    ;

access_specifier: PRIVATE COL
                {access_spec = "private" }                                                                                                   
              | PUBLIC COL 
                {access_spec = "public";   }  
              | PROTECTED COL
                {access_spec = "protected"; }
              | {access_spec = "public";   } 
              ;


section_body: access_specifier declstmt
            | access_specifier FuncDecl
            ;

object_decl : ID ID Multiobj SEMICOL
          | ID ID ASSGN function_call Multiobj SEMICOL
          | ID ID ASSGN ID Multiobj SEMICOL
          ;  

Multiobj : /* empty */
         | COMMA ID
         | COMMA ID ASSGN function_call
         | COMMA ID ASSGN ID
         ;


           
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