#include<bits/stdc++.h>
using namespace std;
class dataframe
{
public:
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
     return data[row][col];
    else 
    {
      std::cout<<"Index or Column out of bounds";
      exit(1);
    }
 } 

 int get_as_int(int i, int j) ;
 int get_as_float(int i, int j) ;
 std::vector<std::string> columns();
 void add_row(std::vector<std::string>row);
 dataframe get(std::vector<std::string>cols);
 dataframe get(std::vector<int>cols);

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

  //get columns
  std::vector<std::string> get_columns(){
      return col_names;
  }

  //write a data frame to csv file
  void write(std::string filename,char delim);

  //drop columns
  void drop(std::vector<std::string>cols);
  void drop(std::vector<int>cols);
  // functions involving predicates
  dataframe select(std::string pred);
  dataframe delete_rows(std::string pred);

 private:
   void real_read(std::string s,std::vector<std::string>dtypes,char delim);
   std::string extractSubstring(const std::string& input);
   std::vector<std::string> removeIndices(std::vector<std::string> vec, const std::vector<int>& indices);
};

dataframe::dataframe(/* args */)
{
}

dataframe::~dataframe()
{
}

void dataframe::write(std::string filename,char delim){
    std::ofstream out(filename);
    if(!out.is_open()){
        std::cout<<"Error opening file"<<std::endl;
        return;
    }

    //write data
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[0].size();j++){
            out<<data[i][j];
            if(j!=data[0].size()-1)
                out<<delim;
        }
        out<<std::endl;
    }
    out.close();
}

void dataframe::drop(std::vector<std::string>cols){
    std::vector<int>indices;
    for(int i=0;i<cols.size();i++){
        for(int j=0;j<col_names.size();j++){
            if(cols[i]==col_names[j]){
                indices.push_back(j);
                break;
            }
        }
    }
    std::sort(indices.begin(),indices.end());
    for(int i=0;i<indices.size();i++){
        col_names.erase(col_names.begin()+indices[i]-i);
        col_types.erase(col_types.begin()+indices[i]-i);
        for(int j=0;j<data.size();j++){
            data[j].erase(data[j].begin()+indices[i]-i);
        }
    }
    ncols=col_names.size();
}


void dataframe::drop(std::vector<int>cols){
    std::sort(cols.begin(),cols.end());
    for(int i=0;i<cols.size();i++){
     if(col_names.size()>0)   col_names.erase(col_names.begin()+cols[i]-i);
        col_types.erase(col_types.begin()+cols[i]-i);
        for(int j=0;j<data.size();j++){
            data[j].erase(data[j].begin()+cols[i]-i);
        }
    }
    ncols=col_names.size();
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
             row.push_back(s); s = ""; 
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
   if(col_types[j]!="int" )
   {
      std::cout<<"Warning, coltype declared to a type and requesting as another type\n";
   }

   if((i>=0 && i<nrows)&&(j>=0 && j <ncols))
     return std::stoi(data[i][j]);
    else 
    {
      std::cout<<"Index or Column out of bounds";
      exit(1);
    } 
}

int dataframe::get_as_float(int i, int j)
{
   if(col_types[j]!="float" )
   {
      std::cout<<"Warning, coltype declared to a type and requesting as another type\n";
   }
   if((i>=0 && i<nrows)&&(j>=0 && j <ncols))
     return std::stof(data[i][j]);
    else 
    {
      std::cout<<"Index or Column out of bounds";
      exit(1);
    } 
}

std::vector<std::string> dataframe::columns()
{
    return col_names;
}

void dataframe::add_row(std::vector<std::string>row)
{
    if(row.size()!= col_types.size())
    {
        std::cout<<"Number of fields given to add a row are less than number of columns\n";
        exit(1);
    }
    data.push_back(row);
}

dataframe dataframe::get(std::vector<int>cols)
{
    dataframe n;
    n.nrows = nrows;
    n.ncols = ncols - cols.size();
    n.col_types = removeIndices(col_types,cols); if(col_names.size()>0) n.col_names = removeIndices(col_names,cols);

    for(int i=0;i<nrows;i++)
    {
           n.data.push_back(removeIndices(data[i],cols));
    } 
    return n;
}

dataframe dataframe::select(std::string pred)
{
    dataframe n; n.ncols = ncols; n.nrows = 0; n.col_types = col_types; n.col_names = col_names;
    std::vector<std::string> row;
    // removing all the spaces from the string
    pred.erase(std::remove(pred.begin(), pred.end(), ' '), pred.end());
    if(pred.substr(0,3)=="int")
    {
            std::string ind = extractSubstring(pred); 
            if(ind.size()==0)
            {
                std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                exit(1);
            }  
            int i = atoi(ind.c_str());
            if(!((i>=0 && i <ncols)))
            {
                std::cout<<"dataframe::select error: Index or Column out of bounds\n";
                exit(1);
            }
            int endPos = pred.find(')');
            if(pred.size()<=endPos+2)
            { 
                 std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                 exit(1);
            }
            std::string comp = pred.substr(endPos+1,1);
            if(pred[endPos+2]=='=') { comp = comp + '='; endPos++;} 
            std::string val = pred.substr(endPos+2); int v = atoi(val.c_str()); 
            // searching rows   
            for(int j=0;j<nrows;j++)
            {
              if(comp=="<")  
              {
                if(get_as_int(j,i)<v) 
                {
                    row = data[j]; 
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">")  
              {
                if(get_as_int(j,i)>v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp=="<=")  
              {
                if(get_as_int(j,i)<=v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp==">=")  
              {
                if(get_as_int(j,i)>=v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp=="==")  
              {
                if(get_as_int(j,i)==v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp=="!=")  
              {
                if(get_as_int(j,i)!=v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else 
              {
                  std::cout<<"dataframe::select error:The predicate has illeagal comparator operator\n";
                  exit(1);
              }
            }
            return n;
    }
    else if(pred.substr(0,5)=="float")
    {
            std::string ind = extractSubstring(pred);
            if(ind.size()==0)
            {
                std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                exit(1);
            }  
            int i = atoi(ind.c_str());
            if(!((i>=0 && i <ncols)))
            {
                std::cout<<"dataframe::select error: Index or Column out of bounds\n";
                exit(1);
            }
            int endPos = pred.find(')');
            if(pred.size()<=endPos+2)
            {
                 std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                 exit(1);
            }
            std::string comp = pred.substr(endPos+1,1);
            if(pred[endPos+2]=='=') { comp = comp + '='; endPos++;}
            std::string val = pred.substr(endPos+2); int v = atof(val.c_str());
            // searching rows   
            for(int j=0;j<nrows;j++)
            {
              if(comp=="<")  
              {
                if(get_as_float(j,i)<v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">")  
              {
                if(get_as_float(j,i)>v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="<=")  
              {
                if(get_as_float(j,i)<=v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">=")  
              {
                if(get_as_float(j,i)>v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="==")  
              {
                if(get_as_float(j,i)==v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="!=")  
              {
                if(get_as_float(j,i)!=v) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else 
              {
                  std::cout<<"dataframe::select error:The predicate has illeagal comparator operator\n";
                  exit(1);
              }
            }
            return n;
    }
    else if(pred.substr(0,6)=="string")
    {
            std::string ind = extractSubstring(pred);
            if(ind.size()==0)
            {
                std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                exit(1);
            }  
            int i = atoi(ind.c_str());
            if(!((i>=0 && i <ncols)))
            {
                std::cout<<"dataframe::select error: Index or Column out of bounds\n";
                exit(1);
            }
            int endPos = pred.find(')');
            if(pred.size()<=endPos+2)
            {
                 std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                 exit(1);
            }
            std::string comp = pred.substr(endPos+1,1);
            if(pred[endPos+2]=='=') { comp = comp + '='; endPos++;}
            std::string val = pred.substr(endPos+2); 
            // searching rows   
            for(int j=0;j<nrows;j++)
            {
              if(comp=="<")  
              {
                if(data[j][i]<val) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">")  
              {
                if(data[j][i]>val) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="<=")  
              {
                if(data[j][i]<=val) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">=")  
              {
                if(data[j][i]>=val) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="==")  
              {
                if(data[j][i]==val) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="!=")  
              {
                if(data[j][i]!=val) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else 
              {
                  std::cout<<"dataframe::select error:The predicate has illeagal comparator operator\n";
                  exit(1);
              }
            }
            return n;
    }
    else
    {
         std::cout<<"dataframe::select error:The predicate is ill-formed\n";
         exit(1);
    }
    return n;
}

dataframe dataframe::delete_rows(std::string pred)
{

    dataframe n; n.ncols = ncols; n.nrows = 0; n.col_types = col_types; n.col_names = col_names;
    std::vector<std::string> row;
    // removing all the spaces from the string
    pred.erase(std::remove(pred.begin(), pred.end(), ' '), pred.end());
    if(pred.substr(0,3)=="int")
    {
            std::string ind = extractSubstring(pred); 
            if(ind.size()==0)
            {
                std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                exit(1);
            }  
            int i = atoi(ind.c_str());
            if(!((i>=0 && i <ncols)))
            {
                std::cout<<"dataframe::select error: Index or Column out of bounds\n";
                exit(1);
            }
            int endPos = pred.find(')');
            if(pred.size()<=endPos+2)
            { 
                 std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                 exit(1);
            }
            std::string comp = pred.substr(endPos+1,1);
            if(pred[endPos+2]=='=') { comp = comp + '='; endPos++;} 
            std::string val = pred.substr(endPos+2); int v = atoi(val.c_str()); 
            // searching rows   
            for(int j=0;j<nrows;j++)
            {
              if(comp=="<")  
              {
                if(!(get_as_int(j,i)<v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">")  
              {
                if(!(get_as_int(j,i)>v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp=="<=")  
              {
                if(!(get_as_int(j,i)<=v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp==">=")  
              {
                if(!(get_as_int(j,i)>=v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp=="==")  
              {
                if(!(get_as_int(j,i)==v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
               else if(comp=="!=")  
              {
                if(!(get_as_int(j,i)!=v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else 
              {
                  std::cout<<"dataframe::select error:The predicate has illeagal comparator operator\n";
                  exit(1);
              }
            }
            return n;
    }
    else if(pred.substr(0,5)=="float")
    {
                    std::string ind = extractSubstring(pred);
            if(ind.size()==0)
            {
                std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                exit(1);
            }  
            int i = atoi(ind.c_str());
            if(!((i>=0 && i <ncols)))
            {
                std::cout<<"dataframe::select error: Index or Column out of bounds\n";
                exit(1);
            }
            int endPos = pred.find(')');
            if(pred.size()<=endPos+2)
            {
                 std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                 exit(1);
            }
            std::string comp = pred.substr(endPos+1,1);
            if(pred[endPos+2]=='=') { comp = comp + '='; endPos++;}
            std::string val = pred.substr(endPos+2); int v = atof(val.c_str());
            // searching rows   
            for(int j=0;j<nrows;j++)
            {
              if(comp=="<")  
              {
                if(!(get_as_float(j,i)<v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">")  
              {
                if(!(get_as_float(j,i)>v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="<=")  
              {
                if(!(get_as_float(j,i)<=v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">=")  
              {
                if(!(get_as_float(j,i)>v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="==")  
              {
                if(!(get_as_float(j,i)==v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="!=")  
              {
                if(!(get_as_float(j,i)!=v)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else 
              {
                  std::cout<<"dataframe::select error:The predicate has illeagal comparator operator\n";
                  exit(1);
              }
            }
            return n;
    }
    else if(pred.substr(0,6)=="string")
    {
            std::string ind = extractSubstring(pred);
            if(ind.size()==0)
            {
                std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                exit(1);
            }  
            int i = atoi(ind.c_str());
            if(!((i>=0 && i <ncols)))
            {
                std::cout<<"dataframe::select error: Index or Column out of bounds\n";
                exit(1);
            }
            int endPos = pred.find(')');
            if(pred.size()<=endPos+2)
            {
                 std::cout<<"dataframe::select error:The predicate is ill-formed\n";
                 exit(1);
            }
            std::string comp = pred.substr(endPos+1,1);
            if(pred[endPos+2]=='=') { comp = comp + '='; endPos++;}
            std::string val = pred.substr(endPos+2); 
            // searching rows   
            for(int j=0;j<nrows;j++)
            {
              if(comp=="<")  
              {
                if(!(data[j][i]<val)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">")  
              {
                if(!(data[j][i]>val)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="<=")  
              {
                if(!(data[j][i]<=val)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp==">=")  
              {
                if(!(data[j][i]>=val)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="==")  
              {
                if(!(data[j][i]==val)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else if(comp=="!=")  
              {
                if(!(data[j][i]!=val)) 
                {
                    row = data[j];
                    n.data.push_back(row); row.clear(); n.nrows++;
                }
              }
              else 
              {
                  std::cout<<"dataframe::select error:The predicate has illeagal comparator operator\n";
                  exit(1);
              }
            }
            return n;
    }
    else
    {
         std::cout<<"dataframe::select error:The predicate is ill-formed\n";
         exit(1);
    }
    return n;
}

std::string dataframe::extractSubstring(const std::string& input) {
    size_t startPos = input.find('(');
    size_t endPos = input.find(')', startPos + 1);  // Start searching from startPos + 1

    if (startPos != std::string::npos && endPos != std::string::npos) {
        // Extract substring between '(' and ')'
        return input.substr(startPos + 1, endPos - startPos - 1);
    } else {
        // '(' or ')' not found
        return nullptr;
    }
}

std::vector<std::string> dataframe::removeIndices(std::vector<std::string> vec, const std::vector<int>& indices) {
    // Sort the indices in descending order to avoid issues with shifting positions
    std::vector<int> sortedIndices = indices;
    std::sort(sortedIndices.begin(), sortedIndices.end(), std::greater<size_t>());

    for (int index : sortedIndices) {
        if (index < vec.size()) {
            vec.erase(vec.begin() + index);
        }
    }
    return vec;
}