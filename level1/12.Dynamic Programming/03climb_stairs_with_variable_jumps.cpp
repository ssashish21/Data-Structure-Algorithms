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
	dp[n] = 1;

	for(int i = n - 1 ; i >= 0 ; i--){
		int jump = jumps[i];
		int allpaths = 0;
		//go to the right side upto variable size and collect the paths
		for(int j = i+1 ; j <= i + jump && j <= n ; j++)
			allpaths += dp[j];

		dp[i] = allpaths;
	}
	cout << dp[0];
}