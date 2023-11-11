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
    int override = 0;
};

struct class_table
{
    std::string name;
    std::unordered_map<std::string,vector<std::string>> vars;
    std::unordered_map<std::string,vector<pair<functab,std::string>>> funcs;
    std::pair<std::string,std::string> inherited;
};

extern int scope ;
extern std::vector<std::unordered_map<std::string,symtab>> sym_table_list;
extern std::unordered_map<std::string,vector<functab>> func_table_list;
extern std::unordered_map<std::string,classtab> class_table_list;