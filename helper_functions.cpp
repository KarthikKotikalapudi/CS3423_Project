#include"global.hpp"
#include "helper_functions.hpp"

void insert_symtab(std::string name,std::string type,std::vector<int>dim,int level)
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

void delete_symtab_level(int level)
{
       if(level < sym_table_list.size()){
       for(auto it  : sym_table_list[level])
       {
               delete it.second;
       }
       if(sym_table_list.size()){
              sym_table_list[level].clear();
              sym_table_list.pop_back();
       }
       }
}

symtab search_symtab(std::string name,int level)
{
       int i = level;
       while(i>=0)
       {
            if(!sym_table_list[i][name]) return sym_table_list[i][name];
            i--;
            if(i == 1)      i--;
       }
       return NULL;
}

void insert_functab(std::string name, std::vector<std::string>params, std::string return_type){
       functab function_table = new struct func_table;
       function_table->name = name;
       function_table->params = params;
       function_table->return_type = return_type;
       func_table_list[name].push_back(function_table);
}

functab search_functab(std::string name, std::vector<std::string>args){
       for(auto i : func_table_list[name]){
              if(i->params == args)   return i;
       }
       return NULL;
}