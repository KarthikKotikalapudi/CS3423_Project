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
     char* type;
     char* name;
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
        const char* type;
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
%type <CL> constL MultiDimL
%%
S : Decl Main{}  // a valid program is sequence of declarations, functions
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
                if(!coersible($1,$4)){
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
                if(!coersible($1,$4)){
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
            s2.type = $5.type;
            if($3!=$5.len){
                cout<<"Semantic Error: Diminsions on LHS and RHS are not same \n";
                exit(1);
            }
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch\n";
                            exit(1);
                        }
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
        s2.name = $2.name;
        s2.type = $4;
        var_list.push_back(s2);
    }
    | COMMA ID access2 ASSGN MultiDimL Multideclstmt {
        symbolTable s2;
        s2.name= $2.name;
        s2.type = $5.type;
        if($3!=$5.len){
            cout<<"Semantic Error: Diminsions on LHS and RHS are not same \n";
            exit(1);
        }
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

constL : numbers COMMA constL { 
    $$.len =   $3.len + 1;
        if($3.type!="char"){
            cout<<"Semantic Error: A const list should contain single type consts expected"<<$3.type<<endl;
            exit(1);
        }
        $$.type = $3.type; 
    }
    | FLOAT COMMA constL {  
        $$.len = $3.len +1 ;
        if($3.type!="float"){
            cout<<"Semantic Error: A const list should contain single type consts expected"<<$3.type<<endl;
            exit(1);
        }
        $$.type = $3.type; 
    }
    | STRING COMMA constL { 
        $$.len = $3.len +1;
        if($3.type!="string"){
            cout<<"Semantic Error: A const list should contain single type consts expected"<<$3.type<<endl;
            exit(1);
        }
        $$.type = $3.type; 
         }
    | CHAR COMMA constL { 
        $$.len = $3 +1 ; 
        if($3.type!="char"){
            cout<<"Semantic Error: A const list should contain single type consts expected"<<$3.type<<endl;
            exit(1);
        }
        $$.type = $3.type; 
        }
    | numbers {$$.len = 1; $$.type = "int";}
    | FLOAT { $$.len = 1; $$.type = "float";}
    | STRING {$$.len = 1; $$.type = "string";}
    | CHAR {$$.len = 1 ; $$.type = "char";}
    | BOOL {$$.len = 1; $$.type ="bool";}
    ;


MultiDimL : OBRACE MultiDimL CBRACE {
            $$.len = $2.len +1;
            $$.type = $2.type;
        }
    | MultiDimL COMMA MultiDimL{
            if($1.type!=$3.type || $1.len != $3.len){
                cout<<"Semantic Error: All lists in the RHS should have same characteristics\n";
                exit(1);
            }
            $$.len = $1.len;
            $$.type = $1.type;
        }
    | OBRACE constL CBRACE {
        $$.type = $2.type;
        $$.len =1;
    }
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
              //find dimension of $3 and insert the dimesion for $2
               insert_symtab($2.name,$3,{},scope);
            
               symtab var = search_symtab($2.name,scope,func); //check this,can string be char * 
              if(var)
               {
                //compare the rhs matrix type
                if(strcmp(var->type.c_str(),$3)){
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

            insert_symtab($2.name,$3,{$7.row,$7.col},scope);

         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float\n";
         }      

    }
    ;

MultiMatrixDecl : COMMA ID MATRIX_TYPE MultiMatrixDecl {
       //Assign type to ID , MultiMatrixDecl
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
    | COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl {
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
                if(strcmp(var->type.c_str(),$3)){
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
    | COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl {
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
    | COMMA ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE  MultiMatrixDecl {
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

            insert_symtab($2.name,$3,{$7.row,$7.col},scope);

         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float\n";
         }      

    }
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
 if(!active_class_ptr)
    {   // here we store parameter types in params global variable
        if(search_functab($1.name,params))
    {
        cout<<"Semantic Error: function already declared\n";
        exit(1);
    }
    //inserting function to function table
    insert_functab($1.name,params,$1.ret_type);
    params.clear();
    }
    // inserting function in the class
    else 
    {
        if(search_classfunc($1.name, params,active_class_ptr->name).first)
        {
             cout<<"Semantic Error: function already declared in the class with same signature\n";
        exit(1);
        }
        insert_classfunc(active_class_ptr->name, $1.ret_type, access_spec, params, active_class_ptr);
    }
}
    ;

FuncHead : DATATYPE ID {$$.name = $2; $$.ret_type = $1;}
    | ID ID { if(!search_classtab($1.name))
               {
                cout<<"Semantic Error: The datatype "<<$1.name<<" doesn't exist\n";
                exit(1);
               }
               $$.name = $2; $$.ret_type = $1.name;
             }
    | MATRIX MATRIX_TYPE ID {}
    | DF ID {$$.name = $2; strcpy($$.ret_type,"dataframe");}
    | DATATYPE access_retn ID {string s = $1; 
              for(int i=0;i<$2;i++) s = s + "[]";  
              $$.name = $3; strcpy($$.ret_type,s.c_str());      
              }
    | ID access_retn ID {
        if(!search_classtab($1.name))
               {
                cout<<"Semantic Error: The datatype "<<$1.name<<" doesn't exist\n";
                exit(1);
               }
              string s = $1.name; 
              for(int i=0;i<$2;i++) s = s + "[]";  
              $$.name = $3; strcpy($$.ret_type,s.c_str());
                }
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
     functab fun = search_functab($1,params);
     if(!fun)
     {
            cout<<"Semantic Error: This function is not declared\n";
            exit(1);
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
            strcpy($$,"bool"); // $$ ="bool";
        }
    | OBRAK pred CBRAK { $$ = $2; }
    | NEG pred { strcpy($$,"bool"); /* $$ = "bool";*/ }
    | arg { $$ = $1; }
    | pred COMP pred 
    {
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Comparator operation must be same"<<endl;
            exit(1);
        }
       strcpy($$,"bool")  // $$ = "bool";
    }
    | pred SHIFT pred 
    {
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"||$1=="bool" || $3=="bool"){
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
      //  $$ = dominate($1,$3).c_str();
        strcpy($$,dominate($1,$3).c_str());
    }
    | pred MINUS pred 
    {   
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"||$1=="bool" || $3=="bool"){
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
        // $$ = var->type.c_str();
        strcpy($$,var->type.c_str());
        }
    | uni {$$ = $1;}
    | function_call {$$ = $1;}
    | numbers {
        //arg gets its attribute from child numbers
        $$ = $1;
    }
    | FLOAT {
        strcpy($$,"float"); // $$ = "float";
    }
    | BOOL{
        strcpy($$,"bool"); // $$ = "bool";
    }
    | CHAR{
        strcpy($$,"char"); // $$ = "char";
    } 
    | STRING{
        strcpy($$,"string");        // $$ = "string";
    }
    | ID access{  
        symtab s;
        if((s=search_symtab($1.name,scope,func))){
           if($2 <= s->dim.size()){
                 //  $$ = s->type.substr(0, s->type.size() - 2*$2).c_str();
                 strcpy($$,s->type.substr(0, s->type.size() - 2*$2).c_str());
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
            if(s->type!="int" && s->type!="float"){
                cout<<"Semantic Error: Invalid datatype for Unary operator Expected int or float\n";
                exit(1);
            }
           // $$ = s->type.c_str();
          strcpy($$,s->type.c_str());
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

            if(s->type!="int" && s->type!="float"){
                cout<<"Semantic Error: Invalid datatype for Unary operator Expected int or float\n";
                exit(1);
            }
           if($2 <= s->dim.size()){
               //    $$ = s->type.substr(0, s->type.size() - 2*$2).c_str();
               strcpy($$,s->type.substr(0, s->type.size() - 2*$2).c_str());
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

                if(!($3=="int" || $3=="float")){
                    cout<<"Semantic Error: Invalid RHS type expected int or float\n";
                    exit(1);
                }
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
                if(var->dim.size()<$2){
                    cout<<"Semantic Error: dimensions do not match\n";
                    exit(1);
                }
                string s = var->type.substr(0, var->type.size() - 2*$2);
                if(!coersible(s,$4)){
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
                if(var->dim.size()<$2){
                    cout<<"Semantic Error: dimensions do not match\n";
                    exit(1);
                }
                if(!($4=="int" || $4=="float")){
                    cout<<"Semantic Error: Invalid RHS type expected int or float\n";
                    exit(1);
                }
                string s = var->type.substr(0, var->type.size() - 2*$2);
                if(!coersible(s,$4)){
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
            symtab var = search_symtab($1.name,scope,func);
            pair<string,string> temp = search_classvar($3.name, var->type);
            if(temp.first == ""){
                //error
                cout<<"Semantic Error: A variable must be declared before use\n";
                exit(1);
            }
            if(temp.second != "public"){
                //error
                cout<<"Semantic Error: Variable not accessible\n";
                exit(1);
            }
            if(!coersible(temp.first,$5)){
                //error
                cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                exit(1);
            }
        }
    | ID DOT ID ARTHASSGN rhs 
        {
            symtab var = search_symtab($1.name,scope,func);
            pair<string,string> temp = search_classvar($3.name, var->type);
            if(temp.first == ""){
                //error
                cout<<"Semantic Error: A variable must be declared before use\n";
                exit(1);
            }
            if(temp.second != "public"){
                //error
                cout<<"Semantic Error: Variable not accessible\n";
                exit(1);
            }
            if(!coersible(temp.first,$5)){
                //error
                cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                exit(1);
            }
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
        temp.first = access_spec;
        temp.second = $5.name;
        insert_classtab($2.name,temp);
        active_class_ptr = search_classtab($2.name);
    }
    ;

class_body:
    | section_body class_body
    ;

access_specifier: PRIVATE COL
                {access_spec = "private"; }                                                                                                   
              | PUBLIC COL 
                {access_spec = "public";   }  
              | PROTECTED COL
                {access_spec = "protected"; }
              | {access_spec = "public";   } 
              ;


section_body: access_specifier declstmt
            | access_specifier FuncDecl
            ;

object_decl : ID ID Multiobj SEMICOL{
    classtab c = search_classtab($1.name);
    if(!c)
    {
        cout<<"Semantic Error: class "<<$1.name<<" not found\n";
        exit(1);
    } 
    symtab var = search_symtab($2.name,scope,func);
        if(var)
        {
        cout<<"Semantic Error: variable already declared\n";
        exit(1);
        } 
        insert_symtab($2.name,$1.name,{},scope);
        for(int i=0;i<var_list.size();i++){
            if(var_list[i].type != $1.name)
            {
                cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                exit(1);
            }
            if(search_symtab(var_list[i].name,scope,func))
            {
            cout<<"Semantic Error: variable already declared \n";
            exit(1);
            }
            string s=$1.name;
            for(int j=0;j<var_list[i].dim.size();j++){
                s+="[]";
            }
            insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
        }
        var_list.clear();
    }
    | ID ID ASSGN function_call Multiobj SEMICOL
    | ID ID ASSGN ID Multiobj SEMICOL{
        classtab c = search_classtab($1.name);
        if(!c)
        {
            cout<<"Semantic Error: class "<<$1.name<<" not found\n";
            exit(1);
        } 
        symtab var = search_symtab($2.name,scope,func);
        if(var)
        {
            cout<<"Semantic Error: variable already declared\n";
            exit(1);
        }
        symtab var1 = search_symtab($4.name,scope,func);
        if(var1->type != $1.name)
        {
            cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
            exit(1);
        }
        insert_symtab($2.name,$1.name,{},scope);
        for(int i=0;i<var_list.size();i++){
            if(var_list[i].type != $1.name)
            {
                cout<<"Semantic Error: Types on LHS and RHS are not coersible\n";
                exit(1);
            }
            if(search_symtab(var_list[i].name,scope,func))
            {
            cout<<"Semantic Error: variable already declared \n";
            exit(1);
            }
            string s=$1.name;
            for(int j=0;j<var_list[i].dim.size();j++){
                s+="[]";
            }
            insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
        }
        var_list.clear();
    }
    | ID ID access Multiobj SEMICOL{ 
            symbolTable s2;
            s2.name= $2.name;
            for(int i=0;i<$3;i++){
                s2.dim.push_back(-1);
            }
            var_list.push_back(s2);
            classtab c = search_classtab($1.name);
            if(!c)
            {
                cout<<"Semantic Error: class "<<$1.name<<" not found\n";
                exit(1);
            } 
            for(int i=0;i<var_list.size();i++){
                if(search_symtab(var_list[i].name,scope,func))
                {
                cout<<"Semantic Error: variable already declared\n";
                exit(1);
                }
                string s=$1.name;
                for(int j=0;j<var_list[i].dim.size();j++){
                    s+="[]";
                }
                if(var_list[i].type!=""){
                    if(s != var_list[i].type){
                        cout<<"Semantic Error: Type Mismatch\n";
                        exit(1);
                    }
                }
                insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
            }
            var_list.clear();
    }
    ;  

Multiobj : /* empty */
        | COMMA ID Multiobj{
            symbolTable s;
            s.name= $2.name;
            var_list.push_back(s);
        }
        | COMMA ID ASSGN function_call Multiobj{}
        | COMMA ID ASSGN ID Multiobj{
            symbolTable s;
            s.name = $2.name;
            s.type = $4.type;
            var_list.push_back(s);
        }
        | COMMA ID access Multiobj{
            symbolTable s;
            s.name= $2.name;
            for(int i=0;i<$3;i++){
                s.dim.push_back(-1);
            }
            var_list.push_back(s);
        }
        ;


           
//SORT FUNC
SORT_FUN    : SORT OBRAK start_end_pos COMMA start_end_pos CBRAK SEMICOL
            | SORT OBRAK start_end_pos COMMA start_end_pos COMMA MINUS NUM CBRAK SEMICOL
            ;

start_end_pos : ID
              | ID ARTH rhs {if($3 != "int")
              {
                cout<<"Semantic Error: array can be appended with only a number\n";
                exit(1);
              }}


//decl, select, update, delete 

DF_DECL: DF ID ASSGN DF OBRAK CBRAK SEMICOL { if(search_symtab($2.name,scope,func))

{
 cout<<"Semantic Error: variable already declared\n";
 exit(1);
}
  insert_symtab($2.name,"dataframe",{},0);
 }
        ;

DF_DELETEROW : DELETE OBRAK ID COMMA pred1 CBRAK {   symtab var = search_symtab($3.name,scope,func);
  if(!var )
  {
    cout<<"Semantic Eroor: The variable has to be declared before use\n";
    exit(1);
  }
  if( var->type != "dataframe" )
  {
    cout<<"Semantic Eroor: The variable is not of type datarame\n";
    exit(1);
  }
}
             ;
            
DF_UPDATECOL : UPDATE OBRAK ID COMMA ID COMMA pred1 COMMA rhs CBRAK {   symtab var = search_symtab($3.name,scope,func);
                    if(!var )
                    {
                        cout<<"Semantic Eroor: The variable has to be declared before use\n";
                        exit(1);
                    }
                    if( var->type != "dataframe" )
                    {
                        cout<<"Semantic Eroor: The variable is not of type datarame\n";
                        exit(1);
                    }
                    }
             | UPDATE OBRAK ID COMMA ID COMMA NUL COMMA rhs CBRAK {   symtab var = search_symtab($3.name,scope,func);
                    if(!var )
                    {
                        cout<<"Semantic Eroor: The variable has to be declared before use\n";
                        exit(1);
                    }
                    if( var->type != "dataframe" )
                    {
                        cout<<"Semantic Eroor: The variable is not of type datarame\n";
                        exit(1);
                    }
                    }
             ;

DF_SELECT   : SELECT OBRAK ID COMMA ID COMMA pred1 CBRAK{   symtab var = search_symtab($3.name,scope,func);
                if(!var )
                {
                    cout<<"Semantic Eroor: The variable has to be declared before use\n";
                    exit(1);
                }
                if( var->type != "dataframe" )
                {
                    cout<<"Semantic Eroor: The variable is not of type datarame\n";
                    exit(1);
                }
                // check what second ID is for, if doesn't have special semantics, just copy above block
                }
            ;

pred1 : STRING

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