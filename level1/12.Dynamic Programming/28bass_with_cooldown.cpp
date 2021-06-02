#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int p[n];
	for(int i = 0 ; i < n ; i++){
		cin >> p[i];
	}	

	int buy = -p[0]; 
	int sell = 0; 
	int cool = 0;

	for(int i = 1 ; i < n ; i++){
		int today_price = p[i];

		int newbuy = max(buy , cool - today_price);
		int newsell = max(sell , today_price + buy);
		int newcool = max(cool , sell);

		buy = newbuy;
		sell = newsell;
		cool = newcool;

	}
	cout << sell;

}