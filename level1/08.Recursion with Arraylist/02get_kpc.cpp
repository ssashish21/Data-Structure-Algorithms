#include<iostream>
#include<cstring>
#include<string>
using namespace std;

static string keypad[] = {".;" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tu" , "vwx" ,"yz"};

int getKPC(int input,string output[]){
    if(input == 0){
        output[0] = "";
        return 1;
    }
    string output1[1000];
    int smallOutputSize = getKPC(input/10 , output1 );
    string currentstr = keypad[input%10];
    int k = 0;
    for(int i = 0  ; i < smallOutputSize ; i++){ 
        for(int j = 0 ; j < currentstr.size() ; j++){
            output[k++] =  output1[i] + currentstr[j];
        }
    }
    return k ;
}
int main(){
    int input; cin>>input;
    string *output = new string[1000000];
   
    
    int size = getKPC(input,output);
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
static string key[] = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> kpc(string num){
    if(num.size() == 0){
        vector<string> res(1 , "");
        return res;
    }
    
    vector<string> smallres = kpc(num.substr(1));
    int k = num[0] - '0';
    string fs = key[k];
    vector<string> myres;
    for(char ch : fs){
        for(string str : smallres){
            myres.push_back(ch + str);
        }
    }
    return myres;
}

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    vector<string> ans = kpc(s);
    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
*/