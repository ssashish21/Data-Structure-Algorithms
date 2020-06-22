// https://www.codechef.com/JUNE20B/problems/EOEO

#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
       unsigned long long ts,js;
       cin>>ts;
       unsigned long long tscopy = ts;
       unsigned long long c = 0;
       unsigned long long p = 0;
       
       while(!(ts&1)){
           p++;
           ts/=2;
       }
       js = pow(2,p+1);
       if(js <= tscopy) c = tscopy / js;
       cout<<c<<'\n';
    }
    
    return 0;
}