#include<bits/stdc++.h>
#define vii vector<vector<int>>
#define vi  vector<int>
using namespace std;

void targetSumSubset(vi ar , int idx , string set , int tar){
   if(idx == ar.size()){
       if(tar == 0){
           cout<<set<<"."<<endl;
       }
       
       return;
   }
   if(ar[idx] <= tar)
   targetSumSubset(ar, idx + 1 , set + to_string(ar[idx]) + ", " , tar - ar[idx]);
   targetSumSubset(ar, idx + 1 , set , tar);      


}
int main(){
    int n , tar;
    cin>>n;

    vi ar(n);
    for(int i = 0 ; i < n ; i++)
       cin>>ar[i];

    cin>>tar;
    targetSumSubset(ar , 0 , "", tar);
}