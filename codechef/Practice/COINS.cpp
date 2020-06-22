// https://www.codechef.com/problems/COINS

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxAmount(ll n, ll dp[]){
    if(n <= 4) return n;
    if(dp[n]!=0) return dp[n];
    dp[n] = max(n,maxAmount(n/4,dp) + maxAmount(n/3,dp) + maxAmount(n/2,dp));
    return dp[n];
}
int main() {
    ll n;
    while(cin>>n){
        ll *dp = new ll[n+1];
        cout<<maxAmount(n,dp)<<"\n";
    }
	return 0;
}