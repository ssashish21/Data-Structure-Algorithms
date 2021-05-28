#include<iostream>
#include<cstring>
#include<string>

int pow(int x , int n){
    if(x == 1 || n == 0){
        return 1;
    }

    if(n % 2 == 0) return pow(x,n/2) * pow(x,n/2);
    else return x * pow(x,n-1);
}
using namespace std;
int getAllSubseq(string input,string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallInput = input.substr(1);
    int smallOutputSize = getAllSubseq(smallInput , output);
    for(int i = 0 ; i < smallOutputSize ; i++){
        output[i+smallOutputSize] = input[0] + output[i];
    }

    return 2 * smallOutputSize;
}
int main(){
    string s;
    cin>>s;
    int anslen = pow(2,s.size());
    string *output = new string[anslen];
    
    int size = getAllSubseq(s,output);
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
#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.size() == 0){
        vector<string> res(1, "");
        return res;
    }
    
    vector<string> smallres = gss(s.substr(1));
    vector<string> myres = smallres;
    for(string str : smallres){
        myres.push_back(s[0] + str);
    }
    return myres;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

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