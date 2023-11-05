// inserts the given varianble in the symbol table, provide details of variable
int insert_symtab(std::string name,std::string type,std::vector<int>dim,int level);
// deletes an entire scope in the symbol provided the level
void delete_symtab_level(int level);
// searches the symbol table starting from given level and decrementing one by one, for given name
// and returns the record if found. main bool indicates if search is done from main funnction or other function
symtab search_symtab(std::string name,int level);

int insert_functab(std::string name, int no_of_params, std::vector<std::string>params, std::string return_type);
