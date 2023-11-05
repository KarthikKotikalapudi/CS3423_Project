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
       std::vector<std::string> temp;
       temp.push_back(name);
       std::vector<std::vector<std::string>> v;
       v.push_back(temp);
       v.push_back(params);
       func_table_list[v] = function_table;
}

functab search_functab(std::string name, std::vector<std::string>args){
       std::vector<std::string> temp;
       temp.push_back(name);
       std::vector<std::vector<std::string>> v;
       v.push_back(temp);
       v.push_back(args);
       if(func_table_list[v])   return func_table_list[v];
       return NULL;
}