#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int getMazePath(int sr , int sc , int er , int ec ,string output[]){
        if(er == -1 || ec == -1){
            output[0] == "";
            return 1;
        }
        if(sr == er && sc == ec){
            output[0]= "";
            return 1;
        } 
        if(sr > er && sc > ec) return 0;
        string op1[1000] , op2[1000];
        int smallOutputSize1 = 0, smallOutputSize2 =  0;

        if(sc < ec)
            smallOutputSize1 = getMazePath(sr , sc + 1 ,er, ec, op1);
        if(sr < er)
            smallOutputSize2 = getMazePath(sr + 1 , sc , er , ec , op2);
        
        
        int k = 0 ; 
        for(int i = 0 ; i < smallOutputSize1 ; i++){
            output[k++] = "h" + op1[i];
        }   
        for(int i = 0 ; i < smallOutputSize2 ; i++){
            output[k++] = "v" + op2[i];
        }     
        return k;
}
int main(){
    int row , col; cin>>row>>col;
    string *output = new string[10000];

    int size = getMazePath(0,0,row-1, col-1,output);
    cout<<"[";
    for(int i= 0 ; i < size - 1; i++){
        cout<<output[i]<<", ";
    }
    cout<<output[size -1];
    cout<<"]";
    delete []output;
    return 0;
}