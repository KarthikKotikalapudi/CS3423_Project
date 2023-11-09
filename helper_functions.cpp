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

symtab search_symtab(std::string name,int level, bool func)
{
       int i = level;
       while(i>=0)
       {
            if(!sym_table_list[i][name]) return sym_table_list[i][name];
            i--;
            if(func && i == 1)      i--;
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
              int j = 0;
              for(; j < i->params.size(); i++){
                     if((i->params[j] != args[j]) && (i->params[j] == "float" && args[j] == "int")){
                            break;
                     }
              }
              if(j == i->params.size())   return i;
       }
       return NULL;
}

bool coersible(string a, string b){
       if (a==b) return true;
       if(a =="int" && b=="float" || a=="float" && b=="int" || a=="int" && b=="bool" || a=="bool" && b=="int" || a=="float" && b=="bool" || a=="bool" && b=="float"){
              return true;
       }
       return false;
}

string dominate(string a, string b){
       if (a==b) return a;
       else if(a=="float" || b=="float"){
              if(a=="float") return a;
              return b;
       }
       else{
              if(a=="int")return a;
              return b;
       }
}

int insert_classtab(std::string name, std::pair<std::string,std::string>Inherited){
       classtab c_table = new struct class_table;
       c_table->name = name;
       if(Inherited.second != ""){
              classtab temp = search_classtab(Inherited.second);
              if(!temp){
                     return 1;
              }
              c_table->inherited = Inherited;
       }
       class_table_list[name] = c_table;
       return 0;
}

classtab search_classtab(std::string name){
       auto it = class_table_list.find(name);
       if(it != class_table_list.end()){
              return class_table_list[name];
       }       
       return NULL;
}

void insert_classvar(std::string name, std::string type, std::string access, classtab c){
       std::pair<std::string,std::string> temp;
       temp.first = type;
       temp.second = access;
       c->vars[name] = temp;
}

std::pair<std::string,std::string> search_classvar(std::string name, std::string class_name){
       std::pair<std::string,std::string> temp;
       temp.first = "";
       temp.second = "";
       classtab c = search_classtab(class_name);
       if(!c) return temp;
       auto it = c->vars.find(name);
       if(it != c->vars.end()){
              temp = c->vars[name];
       }
       return temp;
}

void insert_classfunc(std::string name, std::string return_type, std::string access, std::vector<std::string>params, classtab c){
       std::pair<functab,std::string> temp;
       temp.second = access;
       functab function_table = new struct func_table;
       function_table->name = name;
       function_table->params = params;
       function_table->return_type = return_type;
       temp.first = function_table;
       c->funcs[name].push_back(temp);
}

std::pair<functab,std::string> search_classfunc(std::string func_name, std::vector<std::string>params, std::string class_name){
       classtab c = search_classtab(class_name);
       auto it = c->funcs.find(func_name);
       if(it != c->funcs.end()){
              for(auto i: c->funcs[func_name]){
                     if(i.first->params == params)      return i;
              }
       }
       pair<functab,std::string> temp;
       temp.first = NULL;
       return temp;
}