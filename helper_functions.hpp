

typedef struct symbol_table* symtab;

struct symbol_table 
{
    string name;
    string type;
    vector<int> dim;
    int level;
};

int insert_symtab(string name,string type,vector<int>dim,int level);

int delete_symtab_level(int level);


symtab search_symtab();
