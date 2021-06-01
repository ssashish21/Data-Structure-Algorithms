#include<bits/stdc++.h>
using namespace std;

int main(){
	int r, c;
	cin >> r >> c;

	int cost[r][c];
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> cost[i][j];
		}
	}	

	int dp[r][c];

	//dest to dest
	dp[r-1][c-1] = cost[r-1][c-1];

	//only vertical moves, last col
	//no option to move horizontal
	for(int i = r-2 ; i >= 0 ; i--)
		dp[i][c-1] = cost[i][c-1] + dp[i+1][c-1];

	//only horizontal moves, last row
	//no option to move vertical
	for(int j = c-2 ; j >= 0 ; j--)
		dp[r-1][j] = cost[r-1][j] + dp[r-1][j+1];

	//vertical or horizontal
	for(int i = r-2 ; i >= 0 ; i--){
		for(int j = c-2 ; j >= 0 ; j--){
			dp[i][j] = cost[i][j] + min(dp[i+1][j] , dp[i][j+1]);
		}
	}
	cout << dp[0][0];
}