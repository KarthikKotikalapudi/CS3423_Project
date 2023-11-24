#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <class T>
class matrix{
    private:
    vector<vector<T>>M;

    public:
    //intilization can matrix m<int>(3,4);
    matrix(int r,int c){
        M.resize(r);
        for(int i=0;i<r;i++){
            M[i].resize(c);
        }
    }

    //deconstructor
    ~matrix(){
        M.clear();
    }

    //intilization can matrix m<int> = {{1,2,3},{4,5,6}};
     matrix(std::initializer_list<std::initializer_list<T>> init) {
        M.resize(init.size());
        int i = 0;
        for (const auto& row : init) {
            M[i++] = row;
        }
    }

    //transpose of matrix
    matrix transpose(){
        matrix<T>temp(M[0].size(),M.size());
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                temp.M[j][i]=M[i][j];
            }
        }
        return temp;
    }

    //matrix get order
    vector<int> get_order(){
        vector<int>temp;
        temp.push_back(M.size());
        temp.push_back(M[0].size());
        return temp;
    }

    vector<int> getRowCount(){
        return M.size();
    }

    vector<int> getColumnCount(){
        return M[0].size();
    }

    //addition of matrix
    matrix operator+(matrix<T> m){
        // check if both matrix have same order (use above get_order function)
        if(get_order()!=m.get_order()){
            cout<<"Matrix order not same, cannot perform addition"<<endl;
            exit(1);
            return *this;
        }

        matrix<T>temp(M.size(),M[0].size());
        
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                temp.M[i][j]=M[i][j]+m.M[i][j];
            }
        }
        return temp;
    }

    //subtraction of matrix
    matrix operator-(matrix<T> m){
        // check if both matrix have same order (use above get_order function)
        if(get_order()!=m.get_order()){
            cout<<"Matrix order not same, cannot perform substraction"<<endl;
            exit(1);
            return *this;
        }

        matrix<T>temp(M.size(),M[0].size());
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                temp.M[i][j]=M[i][j]-m.M[i][j];
            }
        }
        return temp;
    }

    //assignment of matrix
    matrix operator=(matrix<T> m){
        //check if not intilized use get_order function
        if(get_order()!=m.get_order()){
            cout<<"Matrix order not same, cannot assign"<<endl;
            exit(1);
            return *this;
        }
        M=m.M;
        return *this;
    }

    //multiplication of matrix
    matrix operator*(matrix<T> m){
             //check if both are multiplication compatible (use get_order function)
             if(get_order()[1]!=m.get_order()[0]){
                cout<<"Matrix order not same, cannot be multiplied"<<endl;
                exit(1);
                return *this;
             }
        matrix<T>temp(M.size(),m.M[0].size());
        for(int i=0;i<M.size();i++){
            for(int j=0;j<m.M[0].size();j++){
                for(int k=0;k<M[0].size();k++){
                    temp.M[i][j]+=M[i][k]*m.M[k][j];
                }
            }
        }
        return temp;
    }

    //multiplication of matrix with scalar
    matrix operator*(T x){
        matrix<T>temp(M.size(),M[0].size());
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                temp.M[i][j]=M[i][j]*x;
            }
        }
        return temp;
    }

    //division of matrix with scalar
    matrix operator/(T x){
        
        matrix<T>temp(M.size(),M[0].size());
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                temp.M[i][j]=M[i][j]/x;
            }
        }
        return temp;
    }

    //determinant of matrix
    T determinant(){
        T det=0;

        //check if matrix is square (use get_order function)
        vector<int>temp=get_order();
        if(temp[0]!=temp[1]){
            cout<<"Matrix is not square, cannot determine det"<<endl;
            return 0;
        }

        if(M.size()==1){
            return M[0][0];
        }
        else if(M.size()==2){
            return M[0][0]*M[1][1]-M[0][1]*M[1][0];
        }
        else{
            for(int i=0;i<M.size();i++){
                matrix<T>temp(M.size()-1,M.size()-1);
                for(int j=1;j<M.size();j++){
                    for(int k=0;k<M.size();k++){
                        if(k<i){
                            temp.M[j-1][k]=M[j][k];
                        }
                        else if(k>i){
                            temp.M[j-1][k-1]=M[j][k];
                        }
                    }
                }
                det+=pow(-1,i)*M[0][i]*temp.determinant();
            }
            return det;
        }
    }

    //inverse of matrix
    matrix inverse(){
        matrix<T>temp(M.size(),M.size());
        T det=determinant();
        if(det==0){
            cout<<"Inverse not possible"<<endl;\
            exit(1);
            return *this;
        }
        if(M.size()==1){
            temp.M[0][0]=1/M[0][0];
            return temp;
        }
        else{
            for(int i=0;i<M.size();i++){
                for(int j=0;j<M.size();j++){
                    matrix<T>temp1(M.size()-1,M.size()-1);
                    for(int k=0;k<M.size();k++){
                        for(int l=0;l<M.size();l++){
                            if(k<i&&l<j){
                                temp1.M[k][l]=M[k][l];
                            }
                            else if(k<i&&l>j){
                                temp1.M[k][l-1]=M[k][l];
                            }
                            else if(k>i&&l<j){
                                temp1.M[k-1][l]=M[k][l];
                            }
                            else if(k>i&&l>j){
                                temp1.M[k-1][l-1]=M[k][l];
                            }
                        }
                    }
                    temp.M[i][j]=pow(-1,i+j)*temp1.determinant()/det;
                }
            }
            return temp.transpose();
        }
    }

    
    class matrix_row{
        private:
        vector<T>&row;
        public:
        matrix_row(vector<T>&r):row(r){}

        //access to matrix element M(i,j)
        T& operator[](int j){
            if(j>=row.size()){
                cout<<"Index out of bounds"<<endl;exit(1);
                return row[0];
            }
            return row[j];
        }
    };

    //access to matrix element M[i][j]
    matrix_row operator[](int i){

        // this returns row
        if(i>=M.size()){
            cout<<"Index out of bounds"<<endl;exit(1);
            return M[0];
        }
        return matrix_row(M[i]);
    }


    
};
