#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , fee;
	cin >> n;

	int p[n];
	for(int i = 0 ; i < n ; i++){
		cin >> p[i];
	}	
	cin >> fee;

	int portfolio = -p[0]; // max_portfolio
	int fund = 0; // max_fund

	for(int i = 1 ; i < n ; i++){
		int today_price = p[i];


		portfolio = max(portfolio , fund - today_price);
		fund = max(fund , today_price + portfolio - fee);
	}
	cout << fund;

}