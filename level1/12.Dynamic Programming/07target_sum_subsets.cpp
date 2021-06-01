#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , tar;
    cin >> n;

    int ar[n];
    for(int i = 0 ; i < n ; i++){
        cin >> ar[i];
    }

    cin >> tar;

    bool dp[n + 1][tar + 1];
    for(int j = 1 ; j <= tar ; j++)
        dp[0][j] = false;
    
    for(int i = 0 ; i <= n ; i++)
        dp[i][0] = true;


    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= tar ; j++){
            dp[i][j] = ar[i-1] <= j 
                       ?dp[i-1][j] || dp[i-1][j - ar[i-1]]
                       :dp[i-1][j];
        }
    }

    string res = dp[n][tar] ? "true" : "false";
    cout << res;

}