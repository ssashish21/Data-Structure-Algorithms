#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int dp[n+1];
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3 ; i <= n ; i++){
		dp[i] = dp[i-1] + dp[i-2] * (i-1);
	}	
	cout <<dp[n];
}


// f(n) = f(n-1) + f(n-2) * (n-1);