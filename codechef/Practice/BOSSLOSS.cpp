// https://www.codechef.com/problems/BOSSLOSS

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll int n,m,k;
     cin>>n>>m;
     k=ceil((sqrt(1+8*m)-1)/2);
     if(k<=n)	cout<<k<<endl;
     else	    cout<<-1<<endl;
    }
    return 0;
}