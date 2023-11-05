#include<bits/stdc++.h>

typedef struct symbol_table* symtab;

struct symbol_table 
{
    std::string name;
    std::string type;
    std::vector<int> dim;
    int level;
};

extern int scope ;
extern std::vector<std::unordered_map<std::string,symtab>> sym_table_list;