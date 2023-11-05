#include"global.hpp"
#include "helper_functions.hpp"

int insert_symtab(std::string name,std::string type,std::vector<int>dim,int level)
{
     if(sym_table_list.size()<level+1)
      {
        std::unordered_map<std::string,symtab> newtab;
        sym_table_list.push_back(newtab); // inserting new symbol table for this level
      }

      sym_table_list[level][name] = new struct symbol_table;
      sym_table_list[level][name]->name = name; sym_table_list[level][name]->type = type;
      sym_table_list[level][name]->dim = dim; sym_table_list[level][name]->level = level;
}

int delete_symtab_level(int level)
{
       for(auto it  : sym_table_list[level])
       {
               delete it.second;
       }
       sym_table_list[level].clear();
       sym_table_list.pop_back();
}

symtab search_symtab(std::string name,int level,bool main)
{
       int i = level;
       while(i>=0)
       {
            if(i==1 && main) continue;

            if(!sym_table_list[i][name]) return sym_table_list[i][name];
            i--;
       }
       return NULL;
}