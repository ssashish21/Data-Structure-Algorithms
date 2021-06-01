#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , cap;
	cin >> n;
	int val[n] , wt[n];
	
	for(int i = 0 ; i < n ; i++){
		cin >> val[i];
	}

	for(int i = 0 ; i < n ; i++){
		cin >> wt[i];
	}
	cin >> cap;

	int dp[n + 1][cap + 1];
	memset(dp , 0 , sizeof dp);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= cap ; j++){
			if(wt[i-1] <= j)//not include , include with val
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-wt[i-1]] + val[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n][cap];
}