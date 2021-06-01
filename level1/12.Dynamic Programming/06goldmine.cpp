#include<bits/stdc++.h>
using namespace std;
int main(){
    int r , c;
    cin >> r >> c;
    
    int **gold = new int*[r];

    for(int i = 0 ; i < r ; i++){
        gold[i] = new int[c];
        for(int j = 0 ; j < c ; j++)
            cin >> gold[i][j];
    }
    
    int **dp = new int*[r];
    for(int i = 0 ; i < r ; i++)
        dp[i] = new int[c];
    
    for(int j = c - 1 ; j >= 0 ; j--){
        for(int i = r - 1 ; i >= 0 ; i--){
            if(j == c - 1){
                dp[i][j] = gold[i][j];
            }else if(i == 0){
                dp[i][j] = gold[i][j] + max(dp[i][j+1] , dp[i+1][j+1]);
            } else if(i == r - 1){
                dp[i][j] = gold[i][j] + max(dp[i][j+1] , dp[i-1][j+1]);
            } else {
                dp[i][j] = gold[i][j] + max({dp[i][j+1] , dp[i-1][j+1] , dp[i+1][j+1]});
            }
        }
    }
    
    int ans = dp[0][0];
    for(int i = 0  ; i < r ; i++) 
        ans = max(ans , dp[i][0]);
    
    cout<<ans<<endl;
}