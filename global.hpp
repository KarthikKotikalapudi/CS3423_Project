#include<bits/stdc++.h>
using namespace std;
typedef struct symbol_table* symtab;
typedef struct func_table* functab;

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

extern int scope ;
extern vector<struct symbol_table> var_list;
extern std::vector<std::unordered_map<std::string,symtab>> sym_table_list;
extern std::unordered_map<std::string,vector<functab>> func_table_list;