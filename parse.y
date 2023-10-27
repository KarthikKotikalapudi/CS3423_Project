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
D : D D {}   // the declarations can be of methods or classes
  | GD {} // a global variable declaration
  | FD {} // a function declaration
  |
  ;
FD : sign LBR stmt RBR {
    if(retcnt==0)
    {   // if there are no return statements inside the function, raise error and exit
     printf("Error: syntax error at line %d\n",yylineno);
    fprintf(fp,"\ninvalid statement"); fclose(sq); fclose(fp);
    exit(0);
    }
    }
   ;
sign : DTP  ID LPAR argL RPAR  {
    fprintf(fp," : function definition "); 
    retcnt = 0; // start counting number of return statements, as parsed the signature and entered the function body
    }
     ; 
argL : DTP ID COMMA argL {}
     | DTP ID {} 
     ;
// stmt rule produces all possible sequence of statements with scopes in between 
stmt : stmtL LBR stmt RBR stmt {} // modify this if needed
     | stmtL {}
     ;
stmtL : stmtD stmtL {}
      | {}
      ;  
// these are different types of single statements
stmtD : declstmt | exprstmt SEMI {fprintf(fp," : expression statement ");} 
      | loops | condstmt 
      | CALL ID Z2 POINT Z3 SEMI{fprintf(fp," : call statement with object");}
      | CALL THIS POINT Z3 SEMI{fprintf(fp," : call statement ");}
      | CALL Z3 SEMI{fprintf(fp," : call statement ");}
      | uni SEMI {fprintf(fp," : call statement ");}
      | retstmt
      ;
declstmt : DECL DTP IDL SEMI {fprintf(fp," : declaration statement ");}
        ;
IDL : ID COMMA IDL {}
    | ID {}
    ;
exprstmt : EXPR ID EQL rhs {}
rhs : pred {} // pred variable covers predicates and all types of other valid rhs elements
    ;
arg : ID {} 
    | bin {} 
    | uni {}
    | callstmt {}
    | NUM | TF | CNST 
    ;
bin : BOPR LPAR pred COMMA pred RPAR {} // binary operaters
    ;
uni : UOPR LPAR pred RPAR {} // unary operaters
    ;
condstmt :  condhead DO LBR stmt RBR opt {}
         ;
condhead : ICT LPAR pred RPAR  {fprintf(fp," : conditional statement ");}
   ;
opt :  Z1 LBR stmt RBR {}
    | {}
    ;
Z1 : OTH {fprintf(fp," : conditional statement ");}
   ;
// pred rules produces all valid predicates
pred : pred LOG pred { } 
     | LPAR pred RPAR { }
     | NEG pred
     | predD { }
     ;
// pred produces the basic elements of a general predicate
predD : arg { } 
      | arg COPR arg { }
      ; 

loops : whilehead DO LBR stmt RBR {}
     | forhead  LBR stmt RBR {}
     ;
whilehead :  LOOP WHILE LPAR pred RPAR {fprintf(fp," : loop");}
   ;
forhead : FOR LPAR FD RPAR {fprintf(fp," : loop");} 
   ;
// produces the valid statements inside the paranthesises of for loop
FD : exprstmt SEMI pred SEMI uni {}
   | exprstmt SEMI pred SEMI {}
   ;
// produces all types of call statements
callstmt : CALL ID Z2 POINT Z3 {}
         | CALL THIS POINT Z3 {}
         | CALL Z3{}
         ;
Z2 : LSQ NUM RSQ {}
   | {}
   ;
// to cover different types of functions that can be called 
Z3 : ID LSQ NUM RSQ  LPAR arglist RPAR {}
   | ID LPAR arglist RPAR {}
   ; 
arglist : pred COMMA arglist | pred;
// for return statements
retstmt : RET pred SEMI {fprintf(fp," : return statement");retcnt++;} 
        | RET VOID SEMI {fprintf(fp," : return statement");retcnt++;} 
// for producing class definitions
CD : sign2 LBR classbody RBR {}
   ;
sign2 : CLASS ID LSQ NUM RSQ {fprintf(fp," : class definition");}
      | CLASS ID {}
      ;
classbody : classbody Z8 {}
          | {}
          ;
Z8 : declstmt {}
   | MD {}
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
    char tokf[50], pars[50];
    snprintf(tokf,sizeof(tokf), "./TPP/TPPO/seq_tokens_%s.txt", argv[1]);
    snprintf(pars,sizeof(pars), "./TPP/TPPO/parser_%s.parsed", argv[1]);
    fp = fopen(pars,"w");  //opening the output parsed file
    if(!fp)
    {
        printf("There was an error opening the output file\n");
        return 0;
    }
    sq = fopen(tokf,"w");   //opeing the output seq tokens file
    if(!sq)
    {
        printf("There was an error opening the output token file\n");
        return 0;
    }
    fprintf(sq,"Name: Chittepu Rutheesh Reddy\nID: CS21BTECH11014\n");
   yyparse();
   fclose(sq); fclose(fp);
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    fprintf(fp," : invalid statement");
}