#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int price[n];
	for(int i = 0 ; i < n ; i++){
		cin >> price[i];
	}

	int min_price = price[0];
	int today_profit = 0;
	int max_profit = 0;

	for(int i = 0 ; i < n ; i++){
		min_price = min(min_price , price[i]);
		today_profit = price[i] - min_price;
		max_profit = max(max_profit , today_profit);
	}
	cout << max_profit;
}