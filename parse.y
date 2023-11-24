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
bool infun = false;
bool ret=false, cond=false;
string rettype="int";
vector<string> params; 
bool func = true;
classtab active_class_ptr = NULL;
string access_spec;
vector<struct symbol_table> var_list;
vector<std::unordered_map<std::string,symtab>> sym_table_list;
unordered_map<std::string,vector<functab>> func_table_list;
unordered_map<std::string,classtab> class_table_list;





%}
%token FLOAT  MATRIX DF IF ELIF ELSE RETURN BREAK CONT  OBRAK CBRAK OSQA CSQA OBRACE CBRACE  DOT NEG COL SEMICOL  POST VOID
%token COMMA CHAR ASSGN ARTHASSGN  FOR WHILE PRINT INPUT MAIN CLASS PRIVATE PROTECTED PUBLIC INHERITS
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
    int val;
    int dim_len;
    struct F{
        char* name;
        char* ret_type;
    } funcattr;
    struct matrixdim{
        int row;
        int col;
        char*type;
    } MD;
    struct CONSTL{
        int len;
        char* type;
    }CL;
    struct number
    {
        char *type;
        int value;
    }number;
}

%token <type> DATATYPE MATRIX_TYPE 
%token <name> STRING
%token <val> NUM
%type <type> parameter access_specifier class_arg call_expression start_end_pos class_function_call
%type <dim_len> access access2 access_assgn 
%type <type> uni arg rhs pred
%type <number> numbers
%type <funcattr> function_call
%type <funcattr> FuncHead FuncHead_dup
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
    | inputstmt
    | break
    | continue
    ;


// declaration statment      
declstmt : DATATYPE ID Multideclstmt SEMICOL
        {   
            if(active_class_ptr){
                vector<string> var = search_classvar($2.name,active_class_ptr->name); 
                if(var[0] != "" && var[2] != "1")
                {
                cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
                } 
                insert_classvar($2.name,$1,access_spec,active_class_ptr,0);
                for(int i=var_list.size()-1;i>=0;i--){
                    vector<string> temp = search_classvar(var_list[i].name,active_class_ptr->name);
                    if(temp[0] !="" && temp[2] != "1")
                    {
                    cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

                            exit(1);
                        }
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr,0);
                }
                var_list.clear();
            }
            else{
                symtab var = search_symtab($2.name,scope,func,1); //check this,can string be char * 
                if(var)
                {
                cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
                } 
                insert_symtab($2.name,$1,{},scope);
                for(int i=var_list.size()-1;i>=0;i--){
                    if(search_symtab(var_list[i].name,scope,func,1))
                    {
                    cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

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
                for(int i=var_list.size()-1;i>=0;i--){
                    vector<string> temp = search_classvar(var_list[i].name,active_class_ptr->name);
                    if(temp[0] !="" && temp[2] != "1")
                    {
                    cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

                            exit(1);
                        }
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr,0);
                }
                var_list.clear();
            }
            else{
                for(int i=var_list.size()-1;i>=0;i--){
                    if(search_symtab(var_list[i].name,scope,func,1))
                    {
                    cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

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
                vector<string> var = search_classvar($2.name,active_class_ptr->name); //check this,can string be char * 
                if(var[0] != "" && var[2] != "1")
                {
                cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
                }
                if(!coersible($1,$4)){
                    cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                } 
                insert_classvar($2.name,$1,access_spec,active_class_ptr,0);
                for(int i=var_list.size()-1;i>=0;i--){
                    vector<string> temp = search_classvar(var_list[i].name,active_class_ptr->name);
                    if(temp[0] !="" && temp[2] != "1")
                    {
                    cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

                            exit(1);
                        }
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr,0);
                }
                var_list.clear();
            }
            else{
                symtab var = search_symtab($2.name,scope,func,1); //check this,can string be char * 
                if(var)
                {
                cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
                }
                if(!coersible($1,$4)){
                    cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                } 
                insert_symtab($2.name,$1,{},scope);
                for(int i=var_list.size()-1;i>=0;i--){
                    if(search_symtab(var_list[i].name,scope,func,1))
                    {
                    cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

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
                cout<<"Semantic Error: Diminsions on LHS and RHS are not same  at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
            }
            for(int i=0;i<$3;i++){
                s2.dim.push_back(-1);
                s2.type+="[]";
            }
            var_list.push_back(s2);
            if(active_class_ptr){
                for(int i=var_list.size()-1;i>=0;i--){
                    vector<string> temp = search_classvar(var_list[i].name,active_class_ptr->name);
                    if(temp[0] !="" && temp[2] != "1")
                    {
                    cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

                            exit(1);
                        }
                    }
                    insert_classvar(var_list[i].name,s,access_spec,active_class_ptr,0);
                }
                var_list.clear();
            }
            else{
                for(int i=var_list.size()-1;i>=0;i--){
                    if(search_symtab(var_list[i].name,scope,func,1))
                    {
                    cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

                    exit(1);
                    }
                    string s=$1;
                    for(int j=0;j<var_list[i].dim.size();j++){
                        s+="[]";
                    }
                    if(var_list[i].type!=""){
                        if(!coersible(s,var_list[i].type)){
                            cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
                                std::cout << "Error at line: " << __LINE__ << std::endl;

                            exit(1);
                        }
                    }
                    insert_symtab(var_list[i].name,s,var_list[i].dim,scope);
                }
                var_list.clear();
            }
        }
    | MATRIX MultiMatrixDecl SEMICOL {}
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
            cout<<"Semantic Error: Diminsions on LHS and RHS are not same  at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
        }
        for(int i=0;i<$3;i++){
            s2.type+="[]";
            s2.dim.push_back(-1);
        }
        var_list.push_back(s2);
    }
    | /* empty */
    ;

numbers : NUM {
          $$.value = $1; 
         $$.type = strdup("int");
       }
     | MINUS NUM {
        $$.value = $2; 
        $$.type = strdup("int");
     }
     ;

constL : numbers COMMA constL { $$.len =   $3.len + 1; if(strcmp($3.type,"int")){cout<<"Semantic error:constants are not of same type at line no: "<<yylineno<<"\n";    std::cout << "Error at line: " << __LINE__ << std::endl;
 exit(1);}  $$.type = strdup("int"); }
    | FLOAT COMMA constL {  $$.len = $3.len +1 ;if(strcmp($3.type,"float")){cout<<"Semantic error:constants are not of same type at line no: "<<yylineno<<"\n";     std::cout << "Error at line: " << __LINE__ << std::endl;
exit(1);}  $$.type = strdup("float");}
    | STRING COMMA constL { $$.len = $3.len +1; if(strcmp($3.type,"string")){cout<<"Semantic error:constants are not of same type at line no: "<<yylineno<<"\n";    std::cout << "Error at line: " << __LINE__ << std::endl;
 exit(1);}  $$.type = strdup("string");}
    | CHAR COMMA constL { $$.len = $3.len +1 ;if(strcmp($3.type,"char")){cout<<"Semantic error:constants are not of same type at line no: "<<yylineno<<"\n";     std::cout << "Error at line: " << __LINE__ << std::endl;
exit(1);}  $$.type = strdup("char");}
    | BOOL COMMA constL { $$.len = $3.len +1 ;if(strcmp($3.type,"bool")){cout<<"Semantic error:constants are not of same type at line no: "<<yylineno<<"\n";    std::cout << "Error at line: " << __LINE__ << std::endl;
 exit(1);}  $$.type = strdup("bool");}
    | numbers {$$.len = 1; $$.type = strdup("int");}
    | FLOAT { $$.len = 1; $$.type = strdup("float");}
    | STRING {$$.len = 1; $$.type = strdup("string");}
    | CHAR {$$.len = 1 ;  $$.type = strdup("char");}
    | BOOL {$$.len = 1; $$.type = strdup("bool");}
    ;


MultiDimL : OBRACE MultiDimL CBRACE {
            $$.len = $2.len +1;
            $$.type = $2.type;
        }
    | MultiDimL COMMA MultiDimL{
            if(strcmp($1.type,$3.type)!=0 || $1.len != $3.len){
                cout<<"Semantic Error: All lists in the RHS should have same characteristics at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

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

MatrixDecl : 
        ID MATRIX_TYPE ASSGN rhs{
            symtab var = search_symtab($1.name,scope,func,1); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(!strcmp(mtype,$2) || !strcmp(mtype1,$2)){
              //add matrix with type int or float
              //find dimension of $3 and insert the dimesion for $2
               insert_symtab($1.name,$2,{},scope);
            if(strcmp($2,$4)){
                cout<<"Semantic Error: Both sides of assignment operator must be of same type at line no: "<<yylineno<<"\n";
                exit(1);
            }       
        }
         else{
             cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
                 std::cout << "Error at line: " << __LINE__ << std::endl;

         }
    
    }
    | ID MATRIX_TYPE OBRAK numL CBRAK{
       
             symtab var = search_symtab($1.name,scope,func,1); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(!strcmp(mtype,$2) || !strcmp(mtype1,$2)){
            //add matrix with type int or float
            // also patch the dimensions from numL
            insert_symtab($1.name,$2,{$4.row,$4.col},scope);
         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
                 std::cout << "Error at line: " << __LINE__ << std::endl;

         }

    }
    | ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE {
                        symtab var = search_symtab($1.name,scope,func,1); //check this,can string be char * 
           if(var)
           {
            cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
           } 
         
         char mtype[] = "<int>";
         char mtype1[] = "<float>";
         if(!strcmp(mtype,$2) || !strcmp(mtype1,$2)){
            //add matrix with type int or float
            // also patch the dimensions from MAtrixL
            if(!strcmp($2,$6.type)){
                 cout<<"The assigned constant matrix is different from the variable matrix declared here at line no: "<<yylineno<<"\n";
                 exit(1);  
            }
            insert_symtab($1.name,$2,{$6.row,$6.col},scope);

         }
         else{
             cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
                 std::cout << "Error at line: " << __LINE__ << std::endl;

         }      

    }
    ;


// MultiMatrixDecl : COMMA ID MATRIX_TYPE MultiMatrixDecl 
//     {
//        //Assign type to ID , MultiMatrixDecl
//        symtab var = search_symtab($2.name,scope,func,1); //check this,can string be char * 
//            if(var)
//            {
//             cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
//                 std::cout << "Error at line: " << __LINE__ << std::endl;

//             exit(1);
//            } 
         
//          char mtype[] = "<int>";
//          char mtype1[] = "<float>";
//          if(!strcmp(mtype,$3) || !strcmp(mtype1,$3)){
//             //add matrix with type int or float
//             insert_symtab($2.name,$3,{},scope);
//          }
//          else{
//              cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
//                  std::cout << "Error at line: " << __LINE__ << std::endl;

//          }
//     }
//     | COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl 
//     {
//             symtab var = search_symtab($2.name,scope,func,1); //check this,can string be char * 
//            if(var)
//            {
//             cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
//                 std::cout << "Error at line: " << __LINE__ << std::endl;

//             exit(1);
//            } 
         
//          char mtype[] = "<int>";
//          char mtype1[] = "<float>";
//          if(!strcmp(mtype,$3) || !strcmp(mtype1,$3)){
//               //add matrix with type int or float
//                insert_symtab($2.name,$3,{},scope);
            
//                symtab var = search_symtab($5.name,scope,func,0); //check this,can string be char * 
//               if(var)
//                {
//                 //compare the rhs matrix type
//                 if(!strcmp(var->type.c_str(),$3)){
//                     //do nothing
//                 }
//                 else{
//                     cout<<"Semantic Error: Martices are of different types at line no: "<<yylineno<<"\n";
//                         std::cout << "Error at line: " << __LINE__ << std::endl;

//                 }
//                } 
//                else{
//                 cout<<"Semantic Error: variable not declared at line no: "<<yylineno<<"\n";
//                     std::cout << "Error at line: " << __LINE__ << std::endl;

//                 exit(1);
//                }
//          }
//          else{
//              cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
//                  std::cout << "Error at line: " << __LINE__ << std::endl;

//          }
//     }
//     | COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl 
//     {
//            symtab var = search_symtab($2.name,scope,func,1); //check this,can string be char * 
//            if(var)
//            {
//             cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
//                 std::cout << "Error at line: " << __LINE__ << std::endl;

//             exit(1);
//            } 
         
//          char mtype[] = "<int>";
//          char mtype1[] = "<float>";
//          if(!strcmp(mtype,$3) || !strcmp(mtype1,$3)){
//             //add matrix with type int or float
//             // also patch the dimensions from numL
//             insert_symtab($2.name,$3,{$5.row,$5.col},scope);
//          }
//          else{
//              cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
//                  std::cout << "Error at line: " << __LINE__ << std::endl;

//          }
//     }
//     | COMMA ID MATRIX_TYPE ASSGN OBRACE open_marker MatrixL closing_marker CBRACE  MultiMatrixDecl 
//     {
//          symtab var = search_symtab($2.name,scope,func,1); //check this,can string be char * 
//            if(var)
//            {
//             cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
//                 std::cout << "Error at line: " << __LINE__ << std::endl;

//             exit(1);
//            } 
         
//          char mtype[] = "<int>";
//          char mtype1[] = "<float>";
//          if(!strcmp(mtype,$3) || !strcmp(mtype1,$3)){
//             //add matrix with type int or float
//             // also patch the dimensions from MAtrixL
//             if(strcmp($3,$7.type)){
//                  cout<<"The assigned constant matrix is different from the variable matrix declared here at line no: "<<yylineno<<"\n";
//                  exit(1);  
//             }
//             insert_symtab($2.name,$3,{$7.row,$7.col},scope);

//          }
//          else{
//              cout<<"Semantic Error: Matrix can only have int or float at line no: "<<yylineno<<"\n";
//                  std::cout << "Error at line: " << __LINE__ << std::endl;

//          }      

//     }
//     | /* empty */

//     ;

//new decl

MultiMatrixDecl : MultiMatrixDecl COMMA MatrixDecl
                | MatrixDecl
                ;
numL : numbers COMMA numbers {
            $$.row = $1.value;
            $$.col = $3.value;
      }
    ;

MatrixL : OBRACE open_marker constL closing_marker CBRACE  COMMA MatrixL {
                //get the dimesion from inner MatrixL and constL
                $$.row = $7.row + 1;
                if($7.col != $3.len ){
                    cout<<"Intiliaztion of Matrix with jagged array is not allowed"<<endl;
                    exit(1);
                }
                $$.col = $3.len;
                $$.type = $3.type;
       }
    | OBRACE open_marker constL closing_marker CBRACE {
               //get the dimesion from constL
               $$.row = 1;
               $$.col = $3.len;
               $$.type = $3.type;
    }
    ;

//function declaration
FuncDecl : FuncHead_dup OBRACE open_marker open_func FuncBody close_func closing_marker CBRACE{
    rettype = "int";
}
open_func: {infun = true;};
close_func: {infun = false;};
FuncHead_dup :FuncHead  OBRAK params CBRAK 
    {
        //search if this function already exists
        rettype =$1.ret_type;
        if(!active_class_ptr)
        {   // here we store parameter types in params global variable
            if(search_functab($1.name,params))
        {
            cout<<"Semantic Error: function already declared at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
        }
        //inserting function to function table
        insert_functab($1.name,params,$1.ret_type);
        params.clear();
        }
        // inserting function in the class
        else 
        {
            functab f = search_classfunc($1.name, params,active_class_ptr->name).first;
            if(f && !f->override)
            {
                cout<<"Semantic Error: function already declared in the class with same signature at line no: "<<yylineno<<"\n";
                        std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
            }
            insert_classfunc($1.name, $1.ret_type, access_spec, params, active_class_ptr,0);
            params.clear();
        }
    }
    | FuncHead OBRAK CBRAK{
        rettype =$1.ret_type;
        //search if this function already exists
        if(!active_class_ptr)
        {   // here we store parameter types in params global variable
            if(search_functab($1.name,{}))
        {
            cout<<"Semantic Error: function already declared at line no: "<<yylineno<<"\n";
            exit(1);
        }
        //inserting function to function table
        insert_functab($1.name,{},$1.ret_type);
        }
        // inserting function in the class
        else 
        {
            functab f = search_classfunc($1.name, {},active_class_ptr->name).first;
            if(f && !f->override)
            {
                cout<<"Semantic Error: function already declared in the class with same signature at line no: "<<yylineno<<"\n";
                exit(1);
            }
            insert_classfunc(active_class_ptr->name, $1.ret_type, access_spec, {}, active_class_ptr,0);
        }
        }
    ;

FuncHead : DATATYPE ID {$$.name = $2.name; $$.ret_type = $1;}
    | ID ID { if(!search_classtab($1.name))
               {
                cout<<"Semantic Error: The datatype "<<$1.name<<" doesn't exist at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
               }
               $$.name = $2.name; $$.ret_type = $1.name;
             }
    | MATRIX MATRIX_TYPE ID {string s = $2; $$.ret_type = strdup(s.c_str()); $$.name = $3.name; }
    | DF ID {$$.name = $2.name; $$.ret_type =$$.name = strdup("dataframe[][]");}
    | VOID ID {$$.name = $2.name; $$.ret_type = strdup("void");}
    ;

params : parameter COMMA params {params.push_back($1);}
    | parameter {params.push_back($1);}
    ;

parameter : DATATYPE ID 
    { // sending datatypes for inserting function
    $$ = $1;
    // checking if same name is used for different parameters
    symtab par = search_symtab($2.name,scope+1,func,1);
    if(par)
                {
                cout<<"Semantic Error: two parameters cannot have same name at line no: "<<yylineno<<"\n Parameter name "<<$2.name<<" is already used at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
            } 
            $$ = $1;
            insert_symtab($2.name,$1,{},scope+1);
    }
    | MATRIX ID MATRIX_TYPE {string s = "matrix"; s = s + $3;  $$ = strdup(s.c_str());
            symtab par = search_symtab($2.name,scope+1,func,1);
            if(par)
            {
            cout<<"Semantic Error: two parameters cannot have same name at line no: "<<yylineno<<"\n Parameter name "<<$2.name<<" is already used at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
            }  
            $$ = $3;
            vector<int>dim(2,-1);
            insert_symtab($2.name,$3,dim,scope+1);
    }
    | DATATYPE ID access2 {string dt = $1;
       for(int i = 0; i < $3; i++)  dt = dt+"[]";
       char* temp = new char[dt.length()+1]; strcpy(temp,dt.c_str());
       $$ = temp;
        symtab par = search_symtab($2.name,scope+1,func,1);
        if(par)
            {
            cout<<"Semantic Error: two parameters cannot have same name at line no: "<<yylineno<<"\n Parameter name "<<$2.name<<" is already used at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
            } 
        vector<int>dim($3,-1);
        insert_symtab($2.name,$1,dim,scope+1);        
       }
    | ID ID {
            if(!search_classtab($1.name))
               {
                cout<<"Semantic Error: The datatype "<<$1.name<<" doesn't exist at line no: "<<yylineno<<"\n";
                    std::cout << "Error at line: " << __LINE__ << std::endl;

                exit(1);
               }
            $$ = $1.name; 
             symtab par = search_symtab($2.name,scope+1,func,1);
            if(par)
            {
            cout<<"Semantic Error: two parameters cannot have same name at line no: "<<yylineno<<"\n Parameter name "<<$2.name<<" is already used at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
            } 
            vector<int>dim(2,-1);
            insert_symtab($2.name,$1.name,dim,scope+1);
            }
    | ID ID access2 {
                 if(!search_classtab($1.name))
               {
                cout<<"Semantic Error: The datatype "<<$1.name<<" doesn't exist at line no: "<<yylineno<<"\n";
                exit(1);
               }
            string s = $1.name;
            for(int i = 0; i < $3; i++)  s =s+"[]";
            $$ = strdup(s.c_str()); 
            symtab par = search_symtab($2.name,scope+1,func,1);
            if(par)
            {
            cout<<"Semantic Error: two parameters cannot have same name at line no: "<<yylineno<<"\n Parameter name "<<$2.name<<" is already used at line no: "<<yylineno<<"\n";
            exit(1);
            } 
        vector<int>dim($3,-1);
        insert_symtab($2.name,$1.name,dim,scope+1); 
           }
    | DF ID {
            string temp = "dataframe[][]";
            $$ = strdup(temp.c_str()); 
            symtab par = search_symtab($2.name,scope+1,func,1);
            if(par)
            {
                cout<<"Semantic Error: two parameters cannot have same name at line no: "<<yylineno<<"\n Parameter name "<<$2.name<<" is already used at line no: "<<yylineno<<"\n";
                std::cout << "Error at line: " << __LINE__ << std::endl;

            exit(1);
            }
            vector<int>dim(2,-1);
            insert_symtab($2.name,"dataframe[][]",dim,scope+1);
    }
    ;

FuncBody : stmt 
        {
            if(!ret){
                cout<<"Semantic Error: Function must have atleast one return satement at line no: "<<yylineno<<"\n";
                exit(1);
            }
            ret = false;
        }
         ; 

varL: rhs {params.push_back($1);}
    | rhs COMMA varL {params.push_back($1);}
    ;

function_call:ID OBRAK varL CBRAK  {
        if(!active_class_ptr){
            functab fun = search_functab($1.name,params);
               if(!fun)
               {
                cout<<"Semantic Error: This function doesn't exist at line no: "<<yylineno<<"\n";
                exit(1);
               }
               $$.name = $1.name; $$.ret_type =strdup((fun->return_type).c_str());
               params.clear();    
        }   
        else{
            pair<functab,string> temp;
            temp = search_classfunc($1.name, params, active_class_ptr->name);
            functab fun = temp.first;
            if(!temp.first)
               {
                cout<<"Semantic Error: This function doesn't exist at line no: "<<yylineno<<"\n";
                exit(1);
               }
            $$.name = $1.name; $$.ret_type =strdup((fun->return_type).c_str());
            params.clear();    
        }        
    }
    | ID OBRAK CBRAK {
        if(!active_class_ptr){
            functab fun = search_functab($1.name,{});
               if(!fun)
               {
                cout<<"Semantic Error: This function doesn't exist at line no: "<<yylineno<<"\n";
                exit(1);
               }
               $$.name = $1.name; $$.ret_type =strdup((fun->return_type).c_str());
               params.clear();    
        }   
        else{
            pair<functab,string> temp;
            temp = search_classfunc($1.name, {}, active_class_ptr->name);
            functab fun = temp.first;
            if(!temp.first)
               {
                cout<<"Semantic Error: This function doesn't exist at line no: "<<yylineno<<"\n";
                exit(1);
               }
            $$.name = $1.name; $$.ret_type =strdup((fun->return_type).c_str());
        }    
    }
    | DF_UPDATECOL { $$.name = strdup("update"); $$.ret_type = strdup("dataframe[][]");}
    | DF_SELECT {$$.name = strdup("select");$$.ret_type = strdup("dataframe[][]");}
    | DF_DELETEROW {$$.name = strdup("delete");$$.ret_type = strdup("dataframe[][]");;}
    ;
call_expression: function_call {
    $$=strdup(($1.ret_type));
}
callstmt: function_call SEMICOL {
     }
    | class_arg SEMICOL
    | SORT_FUN
    ;

class_arg:
     ID DOT ID{
        symtab x = search_symtab($1.name,scope,func,0);
        if(!x){
            cout<<"Semantic Error: Variable is not declared in this scope at line no: "<<yylineno<<"\n";
            exit(1);
        }
        string class_name = x->type;
        if(class_name == "<int>")   class_name = "matrix<int>";
        if(class_name == "<float>")   class_name = "matrix<float>";
        if(!search_classtab(class_name)){
              cout<<"Semantic Error: Variable is not of class type at line no: "<<yylineno<<"\n";
              exit(1);
        }
        vector<string> M = search_classvar($3.name, class_name);
        if(M[0]==""){
              cout<<"Semantic Error: Variable is not declared in the class at line no: "<<yylineno<<"\n";
              exit(1);
        }
        if(M[1]=="private" || M[1]=="protected"){
            cout<<"Semantic Error: Variable cannot be access witout a public method of the same class at line no: "<<yylineno<<"\n";
            exit(1);
        }
        $$ =strdup(x->type.c_str());

     }
    | ID DOT ID access 
    {   symtab x = search_symtab($1.name,scope,func,0);
        if(!x){
            cout<<"Semantic Error: Variable is not declared in this scope at line no: "<<yylineno<<"\n";
            exit(1);
        }
        string class_name = x->type;
        
        if(class_name == "<int>")   class_name = "matrix<int>";
        if(class_name == "<float>")   class_name = "matrix<float>";
        if(!search_classtab(class_name)){
              cout<<"Semantic Error: Variable is not of class type at line no: "<<yylineno<<"\n";
              exit(1);
        }
        vector<string> M = search_classvar($3.name, class_name); 
        if(M[0]==""){
              cout<<"Semantic Error: Variable is not declared in the class at line no: "<<yylineno<<"\n";
              exit(1);
        }
        if(M[1]=="private" || M[1]=="protected"){
            cout<<"Semantic Error: Variable cannot be access witout a public method of the same class"<<endl;
            exit(1);
        }
        string s="",s1=M[0].substr( M.size() - 2*$4,M.size());
        if(M[0][0]=='<'){
            if($4!=2){
                cout<<"Invalid Matrix access at line no: "<<yylineno<<"\n";
                exit(1);
            }
            M[0] = M[0].substr(1,M[0].size()-2);
        }
        else{
            string s="",s1=M[0].substr( M[0].size() - 2*$4, 2*$4);
            for(int j=0;j<$4;j++)s+="[]";
            if(s1!=s){
                cout<<"Semantic Error: dimensions do not match at line no: "<<yylineno<<"\n";
                exit(1);
            }
            M[0] = M[0].substr(0, M[0].size() - 2*$4);
        }
        $$ =strdup(x->type.c_str());
    }
    | ID DOT class_function_call{
        symtab x = search_symtab($1.name,scope,func,0);
        if(!x){
            cout<<"Semantic Error: Variable is not declared in this scope at line no: "<<yylineno<<"\n";
            exit(1);
        }
        string class_name = x->type;
        
        if(class_name == "<int>")   class_name = "matrix<int>";
        if(class_name == "<float>")   class_name = "matrix<float>";
        if(!search_classtab(class_name)){
              cout<<"Semantic Error: Variable is not of class type at line no: "<<yylineno<<"\n";
              exit(1);
        }
        pair <functab,string> M = search_classfunc($3,params,class_name); 
        if(M.first==NULL){
              cout<<"Semantic Error: Method is not declared in the class at line no: "<<yylineno<<"\n";
              exit(1);
        }
        if(M.second=="private" || M.second=="protected"){
            cout<<"Semantic Error:this method cannot be used outside of the class at line no: "<<yylineno<<"\n";
            exit(1);
        }
        params.clear();
        $$ =strdup(x->type.c_str());
    }
    ;

class_function_call: ID OBRAK varL CBRAK{
        $$ = $1.name;
    }
    | ID OBRAK CBRAK{
        $$ = $1.name;
    }
    ;

// expression statments    
rhs : pred { $$ = $1;}
    ;

// pred rules produces all valid predicates
pred : pred LOG pred 
        {
            $$ =strdup("bool"); // $$ ="bool";
        }
    | OBRAK pred CBRAK { $$ = $2; }
    | NEG pred { $$ = strdup("bool"); /* $$ = "bool";*/ }
    | arg { $$ = $1; }
    | pred COMP pred 
    {
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Comparator operation must be same"<<endl;
            exit(1);
        }
        string s = $1,s1=$3;
        if(s[s.size()-1]==']'||s1[s1.size()-1]==']'){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
       $$ = strdup("bool");  // $$ = "bool";
    }
    | pred SHIFT pred 
    {
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"||$1=="bool" || $3=="bool"){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        string s = $1,s1=$3;
        if(s[s.size()-1]==']'||s1[s1.size()-1]==']'){
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
        string s = $1,s1=$3;
        if(s[s.size()-1]==']'||s1[s1.size()-1]==']'){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        if(strcmp($1,$3)){
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
        string s = $1,s1=$3;
        if(s[s.size()-1]==']'||s1[s1.size()-1]==']'){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Arthimatic operation must be coersible"<<endl;
            exit(1);
        }
      //  $$ = dominate($1,$3).c_str();
        $$ = strdup(dominate($1,$3).c_str());
    }
    | pred MINUS pred 
    {   
        if($1=="string" || $1=="char"||$3=="string" || $3=="char"||$1=="bool" || $3=="bool"){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        string s = $1,s1=$3;
        if(s[s.size()-1]==']'||s1[s1.size()-1]==']'){
            cout<<"Semantic Error: Invalid input for Arthimatic operation"<<endl;
            exit(1);
        }
        if(!coersible($1,$3)){
            cout<<"Semantic Error: Both sides of the Arthimatic operation must be coersible"<<endl;
            exit(1);
        }
        $$= strdup(dominate($1,$3).c_str()); // $$ = dominate($1,$3).c_str();
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
        symtab var = search_symtab($1.name,scope,func,0); //check this,can string be char * 
        if(!var)
        {
           cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
           exit(1);
        } 
        // $$ = var->type.c_str();
        $$= strdup(var->type.c_str());
        }
    | uni {$$ = $1;}
    | call_expression{$$ = $1;}
    | numbers {
        //arg gets its attribute from child numbers
        $$ = $1.type;
    }
    | FLOAT {
        $$= strdup("float"); // $$ = "float";
    }
    | BOOL{
        $$ = strdup("bool"); // $$ = "bool";
    }
    | CHAR{
        $$ = strdup("char"); // $$ = "char";
    } 
    | STRING{
        $$ = strdup("string");        // $$ = "string";
    }
    | ID access{  
        symtab s;
        if((s=search_symtab($1.name,scope,func,0))){
           if(s->type[0]=='<'){
            if($2!=2){
                cout<<"Invalid Matrix access at line no: "<<yylineno<<"\n";
                exit(1);
            }
            $$ = strdup(s->type.substr(1,s->type.size()-2).c_str());
           }
           else if(s->type=="dataframe[][]"){
            if($2==1){
                $$ =strdup("dataframe[]");
            }
            else if($2==2){
                $$=strdup("dataframe");
            }
            else{
                cout<<"Invalid df access at line no: "<<yylineno<<"\n";
                exit(1);
            }
           }
           else{
                if($2 <= s->dim.size()){
                        //  $$ = s->type.substr(0, s->type.size() - 2*$2).c_str();
                        $$= strdup (s->type.substr(0, s->type.size() - 2*$2).c_str());
                }
                else{
                    cout<<"Semantic error: dimensions do not match at line no: "<<yylineno<<"\n";
                    exit(1);
                }
           }
        }
        else{
        //error
        cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
        exit(1);
      }
    }
    | class_arg {$$ = $1;}
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
               
uni : ID POST {
      symtab s;
       if((s=search_symtab($1.name,scope,func,0))){
            if(s->type!="int" && s->type!="float" && s->type!="dataframe"){
                cout<<"Semantic Error: Invalid datatype for Unary operator Expected int or float at line no: "<<yylineno<<"\n";
                exit(1);
            }
           // $$ = s->type.c_str();
          $$= strdup(s->type.c_str());
        }
      else{
        //error
        cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
        exit(1);
      }
    }
    | ID access POST{
      symtab s;
       if((s=search_symtab($1.name,scope,func,0))){

            if(s->type.substr(0, s->type.size() - 2*$2)!="int" && s->type.substr(0, s->type.size() - 2*$2)!="float" && s->type.substr(0, s->type.size() - 2*$2)!="dataframe"){
                cout<<"Semantic Error: Invalid datatype for Unary operator Expected int or float at line no: "<<yylineno<<"\n";
                exit(1);
            }
           if($2 <= s->dim.size()){
               //    $$ = s->type.substr(0, s->type.size() - 2*$2).c_str();
               $$=strdup(s->type.substr(0, s->type.size() - 2*$2).c_str());
           }
           else{
               cout<<"Semantic error: dimensions do not match at line no: "<<yylineno<<"\n";
               exit(1);
           }
        }
      else{
        //error
        cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
        exit(1);
      }
    }
    ;

// bin : arg ARTH arg 
//     ;

expr : ID ASSGN rhs 
        {   symtab var;
            if((var=search_symtab($1.name,scope,func,0))){
               
                if(!coersible(var->type,$3)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                    exit(1); 
                } 
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    | ID ARTHASSGN rhs 
        {   symtab var;
            if((var=search_symtab($1.name,scope,func,0))){

                if(!($3=="int" || $3=="float"|| $3=="dataframe")){
                    cout<<"Semantic Error: Invalid RHS type expected int or float at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if(!coersible(var->type,$3)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    | ID access ASSGN rhs 
        {   
            symtab var;
            string s;
            if((var=search_symtab($1.name,scope,func,0))){
                if(var->type[0]=='<'){
                    if($2!=2){
                        cout<<"Invalid Matrix access at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    s = var->type.substr(1,var->type.size()-2);
                }
                else {
                    if(var->dim.size()<$2){
                        cout<<"Semantic Error: dimensions do not match at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    s = var->type.substr(0, var->type.size() - 2*$2);
                }
                if(!coersible(s,$4)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    | ID access ARTHASSGN rhs 
        {   symtab var; string s;
            if((var=search_symtab($1.name,scope,func,0))){
                if(var->dim.size()<$2){
                    cout<<"Semantic Error: dimensions do not match at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if(!($4=="int" || $4=="float" || $4=="dataframe")){
                    cout<<"Semantic Error: Invalid RHS type expected int or float at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if(var->type[0]=='<'){
                    if($2!=2){
                        cout<<"Invalid Matrix access at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    s = var->type.substr(1,var->type.size()-2);
                }
                else 
                s = var->type.substr(0, var->type.size() - 2*$2);
                if(!coersible(s,$4)){
                    cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                    exit(1);
                }
            }
            else{
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    | uni { }
    | ID DOT ID ASSGN rhs 
        {
            symtab var = search_symtab($1.name,scope,func,0);
            if(!var){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            string class_name = var->type;
            
        if(class_name == "<int>")   class_name = "matrix<int>";
        if(class_name == "<float>")   class_name = "matrix<float>";
            if(!search_classtab(class_name)){
                cout<<"Semantic Error: Variable is not of class type at line no: "<<yylineno<<"\n";
                exit(1);
            }
            vector<string> temp = search_classvar($3.name, var->type);
            if(temp[0] == ""){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(temp[1] != "public"){
                //error
                cout<<"Semantic Error: Variable not accessible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(!coersible(temp[0],$5)){
                //error
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    | ID DOT ID ARTHASSGN rhs 
        {
            symtab var = search_symtab($1.name,scope,func,0);
            if(!var){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            string class_name = var->type;
            
        if(class_name == "<int>")   class_name = "matrix<int>";
        if(class_name == "<float>")   class_name = "matrix<float>";
            if(!search_classtab(class_name)){
                cout<<"Semantic Error: Variable is not of class type at line no: "<<yylineno<<"\n";
                exit(1);
            }
            vector<string> temp = search_classvar($3.name, var->type);
            if(temp[0] == ""){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(!($5=="int" || $5=="float" || $5=="dataframe")){
                cout<<"Semantic Error: Invalid RHS type expected int or float at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(temp[1] != "public"){
                //error
                cout<<"Semantic Error: Variable not accessible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(!coersible(temp[0],$5)){
                //error
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    | ID DOT ID access ARTHASSGN rhs 
    {
        symtab var = search_symtab($1.name,scope,func,0);
            if(!var){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            string class_name = var->type;
            
        if(class_name == "<int>")   class_name = "matrix<int>";
        if(class_name == "<float>")   class_name = "matrix<float>";
            if(!search_classtab(class_name)){
                cout<<"Semantic Error: Variable is not of class type at line no: "<<yylineno<<"\n";
                exit(1);
            }
            vector<string> temp = search_classvar($3.name, var->type);
            if(temp[0] == ""){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(!($6=="int" || $6=="float"|| $6=="dataframe")){
                cout<<"Semantic Error: Invalid RHS type expected int or float at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(temp[1] != "public"){
                //error
                cout<<"Semantic Error: Variable not accessible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(temp[0][0]=='<'){
                if($4!=2){
                    cout<<"Invalid Matrix access at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                temp[0] = temp[0].substr(1,temp[0].size()-2);
            }
            else{
                string s="",s1=temp[0].substr( temp[0].size() - 2*$4, 2*$4);
                for(int j=0;j<$4;j++)s+="[]";
                if(s1!=s){
                    cout<<"Semantic Error: dimensions do not match at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                temp[0] = temp[0].substr(0, temp[0].size() - 2*$4);
            }
            if(!coersible(temp[0],$6)){
                //error
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
    }
    | ID DOT ID access ASSGN rhs 
    {
        symtab var = search_symtab($1.name,scope,func,0);
            vector<string> temp = search_classvar($3.name, var->type);
            if(temp[0] == ""){
                //error
                cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(temp[1] != "public"){
                //error
                cout<<"Semantic Error: Variable not accessible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(temp[0][0]=='<'){
                if($4!=2){
                    cout<<"Invalid Matrix access at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                temp[0] = temp[0].substr(1,temp[0].size()-2);
            }
            else{
                string s="",s1=temp[0].substr( temp[0].size() - 2*$4, 2*$4);
                for(int j=0;j<$4;j++)s+="[]";
                if(s1!=s){
                    cout<<"Semantic Error: dimensions do not match at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                temp[0] = temp[0].substr(0, temp[0].size() - 2*$4);
            }
            if(!coersible(temp[0],$6)){
                //error
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
    }
    ;

exprstmt : expr SEMICOL
    ;

// conditional statement
condstmt : IF OBRAK pred CBRAK OBRACE open_marker cond_open stmt cond_close closing_marker CBRACE   elif_list
    | IF OBRAK pred CBRAK OBRACE open_marker cond_open stmt cond_close closing_marker CBRACE  elif_list  ELSE OBRACE open_marker cond_open stmt cond_close closing_marker CBRACE 
    ;

elif_list : /* empty */
    | elif_list ELIF OBRAK pred CBRAK OBRACE open_marker cond_open stmt cond_close closing_marker CBRACE 
    ;
            
// loop statements
loop : FOR OBRAK open_marker declstmt  pred SEMICOL expr CBRAK OBRACE cond_open stmt cond_close closing_marker CBRACE 
    | FOR OBRAK open_marker declstmt  pred SEMICOL  CBRAK  OBRACE cond_open stmt cond_close closing_marker CBRACE 
    | FOR OBRAK open_marker exprstmt  pred SEMICOL expr CBRAK  OBRACE cond_open stmt cond_close closing_marker CBRACE 
    | FOR OBRAK open_marker exprstmt  pred SEMICOL  CBRAK  OBRACE cond_open stmt cond_close closing_marker CBRACE 
    | FOR OBRAK open_marker   SEMICOL pred SEMICOL expr CBRAK  OBRACE cond_open stmt cond_close closing_marker CBRACE 
    | FOR OBRAK open_marker   SEMICOL pred SEMICOL  CBRAK  OBRACE cond_open stmt cond_close closing_marker CBRACE 
    | WHILE OBRAK pred CBRAK  OBRACE open_marker cond_open stmt cond_close closing_marker CBRACE 
    ;
cond_open : {cond = true;}
          ;
cond_close: {cond = false;}
          ;
break:
  BREAK SEMICOL
  ;

continue:
  CONT SEMICOL
  ;  

// return statement
returnstmt : RETURN pred SEMICOL 
    {
        if(!cond) ret = true;
        // cout<<$2<<rettype<<endl;
        // cout<<infun<<endl;
        if(infun==true){
            if(!coersible($2,rettype)){
                cout<<"Semantic Error: Return type mismatch at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
        else{
            if(!coersible($2,"int")){
                cout<<"Semantic Error: Return type mismatch at line no: "<<yylineno<<"\n";
                exit(1);
            }
        }
    }
    | RETURN SEMICOL
    {   
        if(!cond) ret = true;
        if(rettype!="void"){
            cout<<"Semantic Error: Return type mismatch at line no: "<<yylineno<<"\n";
            exit(1);
        }
    }
    ;

// print statement
printstmt : PRINT OBRAK multirhs CBRAK SEMICOL
    ;

multirhs : rhs
         | multirhs COMMA rhs
         | 
         ;

inputstmt : INPUT OBRAK ID CBRAK SEMICOL
    {
        if(!search_symtab($3.name, scope, func, 0)){
            cout<<"Semantic Error: ID must be declared before use at line no: "<<yylineno<<"\n";
            exit(1);
        }
    }
          | INPUT OBRAK ID access CBRAK SEMICOL
    {
        symtab var;
        if(!(var=search_symtab($3.name, scope, func, 0))){
            cout<<"Semantic Error: ID must be declared before use at line no: "<<yylineno<<"\n";
            exit(1);
        }
        if(var->dim.size()<$4){
            cout<<"Semantic Error: Invalid arr access (dimension mismatch), at line no: "<<yylineno<<"\n";
            exit(1);
        }
    }
          | INPUT OBRAK ID  DOT ID CBRAK SEMICOL
    {   
        symtab var=search_symtab($3.name, scope, func, 0);
        if(!var){
            cout<<"Semantic Error: object must be declared before use, at line no: "<<yylineno<<"\n";
            exit(1);
        }
        classtab c;
        c = search_classtab(var->type);
        if(!c){
             cout<<"Semantic Error: class must be declared before use, at line no: "<<yylineno<<"\n";
            exit(1);
        }
        vector<string> temp=search_classvar($5.name,var->type);
        if(temp[0] == ""){
            //error
            cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
            exit(1);
        }
        if(temp[1] != "public"){
            //error
            cout<<"Semantic Error: Variable not accessible at line no: "<<yylineno<<"\n";
            exit(1);
        }
        if(temp[0][temp[0].size() - 1]==']'){
            cout<<"Semantic Error: Invalid input type input can only take simple datatype, at line no: "<<yylineno<<"\n";
            exit(1);
        }
    }
          | INPUT OBRAK ID  DOT ID access CBRAK SEMICOL
    {
        symtab var=search_symtab($3.name, scope, func, 0);
        if(!var){
            cout<<"Semantic Error: object must be declared before use, at line no: "<<yylineno<<"\n";
            exit(1);
        }
        classtab c;
        c = search_classtab(var->type);
        if(!c){
             cout<<"Semantic Error: class must be declared before use, at line no: "<<yylineno<<"\n";
            exit(1);
        }
        vector<string> temp=search_classvar($5.name,var->type);
        if(temp[0] == ""){
            //error
            cout<<"Semantic Error: A variable must be declared before use at line no: "<<yylineno<<"\n";
            exit(1);
        }
        if(temp[1] != "public"){
            //error
            cout<<"Semantic Error: Variable not accessible at line no: "<<yylineno<<"\n";
            exit(1);
        }
        string s="",s1=temp[0].substr( temp[0].size() - 2*$6, 2*$6);
        for(int j=0;j<$6;j++)s+="[]";
        if(s1!=s){
            cout<<"Semantic Error: dimensions do not match at line no: "<<yylineno<<"\n";
            exit(1);
        }
        if(temp[0][temp[0].size() - 2*$6-1]==']'){
            cout<<"Semantic Error: Invalid input type input can only take simple datatype, at line no: "<<yylineno<<"\n";
            exit(1);
        }
    }
    ;



//class related syntax

class_decl:  class_head OBRACE open_marker class_body closing_marker CBRACE  SEMICOL{active_class_ptr = NULL;}
   ;

class_head : CLASS ID{
        if(search_classtab($2.name)){
            cout<<"Semantic Error: Class already declared at line no: "<<yylineno<<"\n";
            exit(1);
        }
        pair<string,string> temp;
        insert_classtab($2.name,temp);
        active_class_ptr = search_classtab($2.name);
    }
    | CLASS ID INHERITS access_specifier2 ID{
        //Inheritance

        if(search_classtab($2.name)){
            cout<<"Semantic Error: Class already declared at line no: "<<yylineno<<"\n";
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
              | {} 
              ;

access_specifier2: PRIVATE
                {access_spec = "private"; }                                                                                                   
              | PUBLIC
                {access_spec = "public";   }  
              | PROTECTED
                {access_spec = "protected"; }
              ;


section_body: access_specifier declstmt
            | access_specifier FuncDecl
            ;

object_decl : ID ID Multiobj SEMICOL{
    classtab c = search_classtab($1.name);
    if(!c)
    {
        cout<<"Semantic Error: class "<<$1.name<<" not found at line no: "<<yylineno<<"\n";
        exit(1);
    } 
    symtab var = search_symtab($2.name,scope,func,1);
        if(var)
        {
        cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
        exit(1);
        } 
        insert_symtab($2.name,$1.name,{},scope);
        for(int i=var_list.size()-1;i>=0;i--){
            if(var_list[i].type != $1.name && var_list[i].type != "")
            {
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(search_symtab(var_list[i].name,scope,func,1))
            {
            cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
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
    | ID ID ASSGN function_call Multiobj SEMICOL{
        classtab c = search_classtab($1.name);
        if(!c)
        {
            cout<<"Semantic Error: class "<<$1.name<<" not found at line no: "<<yylineno<<"\n";
            exit(1);
        } 
        symtab var = search_symtab($2.name,scope,func,1);
        if(var)
        {
            cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
            exit(1);
        }
        if(!strcmp(var->type.c_str(),$4.ret_type))
        {
            cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
            exit(1);
        }
        insert_symtab($2.name,$1.name,{},scope);
        for(int i=var_list.size()-1;i>=0;i--){
            if(var_list[i].type != $1.name && var_list[i].type != "")
            {
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(search_symtab(var_list[i].name,scope,func,1))
            {
            cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
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
    | ID ID ASSGN ID Multiobj SEMICOL{
        classtab c = search_classtab($1.name);
        if(!c)
        {
            cout<<"Semantic Error: class "<<$1.name<<" not found at line no: "<<yylineno<<"\n";
            exit(1);
        } 
        symtab var = search_symtab($2.name,scope,func,1);
        if(var)
        {
            cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
            exit(1);
        }
        symtab var1 = search_symtab($4.name,scope,func,0);
        if(var1->type != $1.name)
        {
            cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
            exit(1);
        }
        insert_symtab($2.name,$1.name,{},scope);
        for(int i=var_list.size()-1;i>=0;i--){
            if(var_list[i].type != $1.name && var_list[i].type != "")
            {
                cout<<"Semantic Error: Types on LHS and RHS are not coersible at line no: "<<yylineno<<"\n";
                exit(1);
            }
            if(search_symtab(var_list[i].name,scope,func,1))
            {
            cout<<"Semantic Error: variable already declared  at line no: "<<yylineno<<"\n";
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
                cout<<"Semantic Error: class "<<$1.name<<" not found at line no: "<<yylineno<<"\n";
                exit(1);
            } 
            for(int i=var_list.size()-1;i>=0;i--){
                if(search_symtab(var_list[i].name,scope,func,1))
                {
                cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
                exit(1);
                }
                string s=$1.name;
                for(int j=0;j<var_list[i].dim.size();j++){
                    s+="[]";
                }
                if(var_list[i].type!=""){
                    if(s != var_list[i].type){
                        cout<<"Semantic Error: Type Mismatch at line no: "<<yylineno<<"\n";
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
            s.name = $2.name;
            var_list.push_back(s);
        }
        | COMMA ID ASSGN function_call Multiobj{
            symbolTable s;
            s.name = $2.name;
            s.type = $4.ret_type;
            var_list.push_back(s);
        }
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
SORT_FUN    : SORT OBRAK start_end_pos COMMA start_end_pos CBRAK SEMICOL{
                if(strcmp($3,$5)!=0){
                    cout<<"Semantic Error: Both the arguments should be of the same array at line no: "<<yylineno<<"\n";
                    exit(1);
                }
            }
            | SORT OBRAK start_end_pos COMMA start_end_pos COMMA MINUS NUM CBRAK SEMICOL{
                if($8 != 1){
                    cout<<"Semantic Error: invalid 3rd argument for sort at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if(strcmp($3,$5)!=0){
                    cout<<"Semantic Error: Both the arguments should be of the same array at line no: "<<yylineno<<"\n";
                    exit(1);
                }
            }
            ;

start_end_pos : ID{
    symtab var = search_symtab($1.name,scope,func,0);
    if(!var)
    { 
        cout<<"Semantic Error: array must be declared before use at line no: "<<yylineno<<"\n";
        exit(1);
    }
    if(var->type[var->type.size()-1] != ']' || var->type[var->type.size()-3] == ']')
    { 
        cout<<"Semantic Error: Variable type should be 1-D array at line no: "<<yylineno<<"\n";
        exit(1);
    }
    $$ = $1.name;
}
            | ID ARTH rhs {
                if(strcmp($3,"int")!=0)
                { 
                    cout<<"Semantic Error: array can be appended with only a number at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                symtab var = search_symtab($1.name,scope,func,0);
                if(!var)
                { 
                    cout<<"Semantic Error: array must be declared before use at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if(var->type[var->type.size()-1] != ']' || var->type[var->type.size()-3] == ']')
                { 
                    cout<<"Semantic Error: Variable type should be 1D array at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                $$ = $1.name;
            }
              | ID MINUS rhs {
                if(strcmp($3,"int")!=0)
                { 
                    cout<<"Semantic Error: array can be appended with only a number at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                symtab var = search_symtab($1.name,scope,func,0);
                if(!var)
                { 
                    cout<<"Semantic Error: array must be declared before use at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if(var->type[var->type.size()-1] != ']' || var->type[var->type.size()-3] == ']')
                { 
                    cout<<"Semantic Error: Variable type should be 1-D array at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                $$ = $1.name;
            }
            ;


//decl, select, update, delete 

DF_DECL: DF ID ASSGN DF OBRAK CBRAK SEMICOL { if(search_symtab($2.name,scope,func,1))

{
 cout<<"Semantic Error: variable already declared at line no: "<<yylineno<<"\n";
 exit(1);
}
  insert_symtab($2.name,"dataframe[][]",{-1,-1},scope);
 }
        ;

DF_DELETEROW : DELETE OBRAK ID COMMA pred1 CBRAK {   symtab var = search_symtab($3.name,scope,func,0);
  if(!var )
  {
    cout<<"Semantic Eroor: The variable has to be declared before use at line no: "<<yylineno<<"\n";
    exit(1);
  }
  if( var->type != "dataframe[][]" )
  {
    cout<<"Semantic Eroor: The variable is not of type datarame at line no: "<<yylineno<<"\n";
    exit(1);
  }
}
             ;
            
DF_UPDATECOL : UPDATE OBRAK ID COMMA ID COMMA pred1 COMMA rhs CBRAK {   symtab var = search_symtab($3.name,scope,func,0);
                    if(!var )
                    {
                        cout<<"Semantic Eroor: The variable has to be declared before use at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    if( var->type != "dataframe[][]" )
                    {
                        cout<<"Semantic Eroor: The variable is not of type datarame at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    }
             | UPDATE OBRAK ID COMMA ID COMMA NUL COMMA rhs CBRAK {   symtab var = search_symtab($3.name,scope,func,0);
                    if(!var )
                    {
                        cout<<"Semantic Eroor: The variable has to be declared before use at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    if( var->type != "dataframe[][]" )
                    {
                        cout<<"Semantic Eroor: The variable is not of type datarame at line no: "<<yylineno<<"\n";
                        exit(1);
                    }
                    }
             ;

DF_SELECT   : SELECT OBRAK ID COMMA ID COMMA pred1 CBRAK{   symtab var = search_symtab($3.name,scope,func,0);
                if(!var )
                {
                    cout<<"Semantic Eroor: The variable has to be declared before use at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                if( var->type != "dataframe[][]" )
                {
                    cout<<"Semantic Eroor: The variable is not of type datarame at line no: "<<yylineno<<"\n";
                    exit(1);
                }
                // check what second ID is for, if doesn't have special semantics, just copy above block
                }
            ;

pred1 : STRING
    ;

%%
int main(int argc,char** argv)
{

        // add matrix classes
        pair<string,string> temp;
        insert_classtab("matrix<int>",temp);
        classtab MI= search_classtab("matrix<int>"); 
        insert_classfunc("transpose","matrix<int>","public",{},MI,false);
        insert_classfunc("determinant","int","public",{},MI,false);
        insert_classfunc("inverse","matrix<int>","public",{},MI,false);

        insert_classtab("matrix<float>",temp);
        classtab MF= search_classtab("matrix<float>"); 
        insert_classfunc("transpose","matrix<float>","public",{},MF,false);
        insert_classfunc("determinant","float","public",{},MF,false);
        insert_classfunc("inverse","matrix<float>","public",{},MF,false);


       //anyone add dataframe class in symbol table too
       
 
    
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
    snprintf(tokf,sizeof(tokf), "out_%s.cpp", argv[1]);
    out = fopen(tokf,"w");   //opening the output c++ file
    fprintf(out,"#include\"class_files/dataframe.hpp\"\n#include\"class_files/matrix.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n");
   if(!yyparse())
   {
     //printf("No errors detected\n");
   }
   fclose(out); 
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    //fprintf(fp," : invalid statement");
}