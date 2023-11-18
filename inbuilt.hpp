#include<bits/stdc++.h>


class dataframe
{
private:
    int nrows;
    int ncols;
    
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
 private:
   void real_read(std::string s,std::vector<std::string>dtypes,char delim);
};

dataframe::dataframe(/* args */)
{
}

dataframe::~dataframe()
{
}

void dataframe::real_read(std::string s,std::vector<std::string>dtypes,char delim)
{

}




