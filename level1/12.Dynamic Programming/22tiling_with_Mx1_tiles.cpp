#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    
    int *dp = new int[n + 1];

    for(int i = 1 ; i <= n ; i++){
        if(i < m)       // only vertical
        	dp[i] = 1;
        else if(i == m) // vertical or horizontal
        	dp[i] = 2;
        else            // vertical, n-1 + horizontal, n - m 
        	dp[i] = dp[i-1] + dp[i-m];
    }
    cout<<dp[n];
}