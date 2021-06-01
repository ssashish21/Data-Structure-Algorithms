#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	if(n == 0 || k == 0 || n < k){
		cout << 0;
		return 0;
	}	

	long dp[k+1][n+1];
	memset(dp , 0 , sizeof dp);

	for(int t = 1 ; t <= k ; t++){
		for(int p = 1 ; p <= n ; p++){
			if(p < t){
				dp[t][p] = 0;
			} else if(p == t){
				dp[t][p] = 1;
			} else {
				dp[t][p] = dp[t-1][p-1] + dp[t][p-1] * t;
			}
		}
	}
	cout<<dp[k][n];
}

/*
You are given a number n, representing the number of people.
You are given a number k, representing the number of team.
You are required to print the number of ways in which these
people can be partitioned in k non-empty teams.

base cases:
	team == 0 || people == 0 || people < team
		ans = 0;

	people == team
		ans = 1;

	ans: 
	f(p , t) = f(p-1, t-1) + f(p-1 , t) * t
*/