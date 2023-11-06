// inserts the given varianble in the symbol table, provide details of variable
void insert_symtab(std::string name,std::string type,std::vector<int>dim,int level);
// deletes an entire scope in the symbol provided the level
void delete_symtab_level(int level);
// searches the symbol table starting from given level and decrementing one by one, for given name
// and returns the record if found. main bool indicates if search is done from main funnction or other function
symtab search_symtab(std::string name,int level, bool func);

void insert_functab(std::string name, std::vector<std::string>params, std::string return_type);

functab search_functab(std::string name, std::vector<std::string>args);

bool coersible(string a, string b);

int insert_classtab(std::string name, std::vector<std::string>Inherited);

classtab search_classtab(std::string name);

void insert_classvar(std::string name, std::string type, std::string access, classtab c);

std::pair<std::string,std::string> search_classvar(std::string name, std::string class_name);

void insert_classfunc(std::string name, std::string return_type, std::string access, std::vector<std::string>params, classtab c);

std::pair<functab,std::string> search_classfunc(std::string func_name, std::string class_name);