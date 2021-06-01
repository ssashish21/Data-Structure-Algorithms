#include<bits/stdc++.h>
using namespace std;

int fib_recursion(int n){
	if(n == 0 || n == 1) 
		return n;
	return fib_recursion(n-1) + fib_recursion(n-2);
}


int dp[100];
int fib_memoization(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(dp[n] != -1) return dp[n];
	return dp[n] = fib_memoization(n-1) + fib_memoization(n-2);
}

int fib_realDP(int n){
    int dp[n+1];
    dp[0] = dp[1] = 1;
	for(int i = 2 ; i <= n ; i++)
	    dp[i] = dp[i-1] + dp[i-2];
	    
	return dp[n-1];
}

int main(){
	int n;
	cin >> n;
	memset(dp , - 1 , sizeof(dp));
	
	cout << fib_realDP(n);	
}