#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n = str.length();
    int dp[n+1] = {0};

    dp[0] = dp[1] = 1;
    
    //invalid
    if(str[0]=='0') return 0;
    
    for(int i = 2 ; i <= n; i++){
        if(str[i-1] > '0')
            dp[i] = dp[i-1];
        
        if(str[i-2] == '1' || (str[i-2]=='2' && str[i-1] < '7'))
            dp[i]+= dp[i-2];
    }
    
    cout<<dp[n];
}