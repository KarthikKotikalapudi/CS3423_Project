#include<bits/stdc++.h>
class dataframe
{
private:
    int nrows;
    int ncols;
    std::vector<std::string> col_types;
    std::vector<std::string> col_names;
    std::vector<std::vector<std::string>> data;
    // not caring about column names right now
public:
    dataframe(/* args */);
    ~dataframe();
 void read(std::string s,std::vector<std::string>dtypes)
 {
    real_read(s,dtypes,',');
 }
 void read(std::string s,std::vector<std::string>dtypes,char delim)
 {
         real_read(s,dtypes,delim);
 }
 std::string get(int row,int col)
 {
    if((row>=0 && row<nrows)&&(col>=0 && col <ncols))
     return data[row-1][col-1];
    else 
    {
      std::cout<<"Index or Column out of bounds";
      exit(1);
    }
 } 
 int get_as_int(int i, int j) ;
dataframe& operator=(const dataframe& other) {
    if (this != &other) { // Avoid self-assignment
        nrows = other.nrows;
        ncols = other.ncols;
        col_names = other.col_names;
        col_types = other.col_types;
        data = other.data;
    }
    return *this;
}
 private:
   void real_read(std::string s,std::vector<std::string>dtypes,char delim);
};

dataframe::dataframe(/* args */)
{
}

dataframe::~dataframe()
{
}

void dataframe::real_read(std::string f,std::vector<std::string>dtypes,char delim)
{
    std::ifstream inp(f);
    if(!inp.is_open())
    {
      std::cout<<"Error opening the file. Check if the file exists in the directory or try again\n";
      exit(1);
    } 
    col_types = dtypes; 
    char ch; nrows = 0;
    std::vector<std::string> row;
    std::string s; 
    while(inp.get(ch))
    {
      if(ch!=delim)
      {
         if(ch=='\n')
         {
             row.push_back(s); s = ""; std::cout<<row.size()<<std::endl;
             if(row.size()!=dtypes.size())
             {
               std::cout<<"This CSV file is ill structured. Structure properly and re-read. Remove tailing new line if present\n";
               exit(1);
             }
             nrows++; data.push_back(row);
             row.clear();
         }
         else 
         {
              s = s + ch;
         }
      }
      else 
      {
            row.push_back(s); s = "";
      }
     
    }
    // reached end of file
    row.push_back(s); s = "";
    nrows++; data.push_back(row);
    ncols = data[0].size();

}

int dataframe::get_as_int(int i, int j)
{
   if((i>=0 && i<nrows)&&(j>=0 && j <ncols))
     return std::stoi(data[i-1][j-1]);
    else 
    {
      std::cout<<"Index or Column out of bounds";
      exit(1);
    } 
}
