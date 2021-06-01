#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int jumps[n];
	for(int i = 0 ; i < n ; i++){
		cin >> jumps[i];
	}	

	int dp[n+1];
	fill(dp, dp + n + 1 , INT_MAX);
	dp[n] = 0; // n to n - 0 move but path is 1

	for(int i = n - 1 ; i >= 0 ; i--){
		int jump = jumps[i];
		int mn = INT_MAX;
		for(int j = i+1 ; j <= i + jump && j <= n ; j++)
			mn = min(dp[j] , mn);

		if(mn != INT_MAX) dp[i] = mn + 1;
	}
	cout << dp[0];
}