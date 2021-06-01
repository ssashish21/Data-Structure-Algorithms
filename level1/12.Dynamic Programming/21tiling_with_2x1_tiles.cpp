#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	long dp[n+1];
	dp[1] = 1; // 2 * 1 floor
	dp[2] = 2; // 2 * 2 floor

	for(int i = 3 ; i <= n ; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}	
	cout << dp[n]; // 2 * n floor
}