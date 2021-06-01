#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , amt;
	cin >> n;

	int ar[n];
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}	

	cin >> amt;

	int dp[amt + 1];
	memset(dp , 0 , sizeof dp);
	dp[0] = 1;

	for(int i = 0 ; i < n ; i++){
		for(int j = ar[i] ; j <= amt ; j++){
			dp[j] += dp[j - ar[i]];
		}
	}
	cout << dp[amt];
}