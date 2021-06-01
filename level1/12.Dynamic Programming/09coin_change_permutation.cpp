#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , amt;
	cin >> n;

	int coins[n];
	for(int i = 0 ; i < n ; i++){
		cin >> coins[i];
	}	

	cin >> amt;

	int dp[amt + 1];
	memset(dp , 0 , sizeof dp);
	dp[0] = 1;

	for(int i = 1 ; i <= amt ; i++)
		for(auto coin : coins)
			if(i >= coin) 
				dp[i] += dp[i - coin];
	
	cout << dp[amt];
}