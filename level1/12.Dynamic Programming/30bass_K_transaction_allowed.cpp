#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k;
    cin >> n;

    int ar[n];
    for(int i = 0 ; i < n ; i++)
        cin >> ar[i];
    
    cin >> k;

    int dp[k + 1][n];
    memset(dp , 0 , sizeof dp);

    for(int t = 1 ; t <= k ; t++){
        int mx = INT_MIN;

        for(int d = 1 ; d < n ; d++){
            mx = max(mx , dp[t - 1][d - 1] - ar[d - 1]);
            dp[t][d] = max(mx + ar[d] , dp[t][d-1]);
        }
    }

    cout<<dp[k][n-1];
}