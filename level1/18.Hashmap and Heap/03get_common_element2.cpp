#include "bits/stdc++.h"
using namespace std;
int main(){
    int n1; cin >> n1; int ar1[n1];
    for(int i = 0 ; i < n1 ; i++) 
        cin>>ar1[i];

    int n2; cin >> n2; int ar2[n2];
    for(int i = 0 ; i < n2 ; i++)
        cin>>ar2[i];

    unordered_map<int , int> ump;
    for(int i = 0 ; i < n1 ; i++)
        ump[ar1[i]] += 1;

    for(int i = 0 ; i < n2 ; i++){
        if(ump[ar2[i]] > 0){
            cout<<ar2[i]<<endl;
            ump[ar2[i]]--;
        } else {
            continue;
        }
    }
}