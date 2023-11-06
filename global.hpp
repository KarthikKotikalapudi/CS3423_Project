#include<bits/stdc++.h>
using namespace std;
typedef struct symbol_table* symtab;
typedef struct func_table* functab;
typedef struct class_table* classtab;

struct symbol_table 
{
    std::string name;
    std::string type;
    std::vector<int> dim;
    int level;
};
typedef struct symbol_table symbolTable;

struct func_table 
{
    std::string name;
    std::vector<std::string> params;
    std::string return_type;
};

struct class_table
{
    std::string name;
    std::unordered_map<std::string,pair<std::string,std::string>> vars;
    std::unordered_map<std::string,pair<functab,std::string>> funcs;
    std::pair<std::string,std::string> inherited;
};

extern int scope ;
extern std::vector<struct symbol_table> var_list;
extern std::vector<std::unordered_map<std::string,symtab>> sym_table_list;
extern std::unordered_map<std::string,vector<functab>> func_table_list;
extern std::unordered_map<std::string,classtab> class_table_list;