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

	int dp[cap + 1];
	memset(dp , 0 , sizeof dp);

	for(int i = 1 ; i <= cap ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i >= wt[j])
				dp[i] = max(dp[i] , dp[i - wt[j]] + val[j]);
		}
	}
	cout << dp[cap];
}