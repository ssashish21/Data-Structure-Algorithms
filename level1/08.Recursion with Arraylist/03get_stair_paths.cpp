#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int getStairPath(int input,string output[]){
        if(input == 0){
            output[0] = "";
            return 1;
        } 
        if(input < 0){
            return 0;
        }

        string op1[100], op2[100] , op3[100];
        int smallOutputSize1 = getStairPath(input - 1 , op1);
        int smallOutputSize2 = getStairPath(input - 2 , op2);
        int smallOutputSize3 = getStairPath(input - 3 , op3);

        int k = 0;
        for(int i = 0  ; i < smallOutputSize1 ; i++){
            output[k++] = "1" + op1[i]; 
        }
        for(int i = 0  ; i < smallOutputSize2 ; i++){
            output[k++] = "2" + op2[i]; 
        }
        for(int i = 0  ; i < smallOutputSize3 ; i++){
            output[k++] = "3" + op3[i]; 
        }
        return k;
}
int main(){
    int input; cin>>input;
    string *output = new string[1000000];
   
    
    int size = getStairPath(input,output);
    cout<<"[";
    for(int i= 0 ; i < size - 1; i++){
        cout<<output[i]<<", ";
    }
    cout<<output[size -1];
    cout<<"]";
    delete []output;
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
vector<string> solve(int n){
    if(n == 0){
        vector<string> res(1 , "");
        return res;
    } 
    if(n < 0){
        vector<string> res;
        return res;
    }
    
    vector<string> p1 = solve(n - 1);
    vector<string> p2 = solve(n - 2);
    vector<string> p3 = solve(n - 3);
    
    vector<string> mres;
    for(auto x : p1) mres.push_back(to_string(1) + x);
    for(auto x : p2) mres.push_back(to_string(2) + x);
    for(auto x : p3) mres.push_back(to_string(3) + x);
    return mres;
    
}
int main(){
    int n; cin >> n;
    vector<string> res = solve(n);
    cout << "[";
    for(int i = 0 ; i < res.size() - 1 ; i++){
        cout << res[i] <<", ";
    }
    cout << res[res.size() - 1] << "]";
}
*/