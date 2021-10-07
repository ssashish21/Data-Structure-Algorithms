#include "bits/stdc++.h"
using namespace std;
int main(){
    string s;
    cin >> s;

    unordered_map<char , int> mp;
    for(char ch : s){
        mp[ch]++;
    }

    char mfc; // max freq char
    int mf = INT_MIN;
    
    for(auto it : mp){
        if(it.second > mf){
            mf = it.second;
            mfc = it.first;
        }
    }

    cout<<mfc<<endl;
}