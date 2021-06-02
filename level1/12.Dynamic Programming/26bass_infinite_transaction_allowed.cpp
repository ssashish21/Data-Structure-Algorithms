#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int p[n];
	for(int i = 0 ; i < n ; i++){
		cin >> p[i];
	}	

	int profit = 0;
	for(int i = 1 ; i < n ; i++){
		if(p[i] > p[i-1])
			profit += p[i] - p[i-1];
	}
	cout << profit;
}