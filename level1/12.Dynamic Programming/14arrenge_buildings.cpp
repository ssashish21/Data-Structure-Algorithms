#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	long oldb = 1 ,olds = 1;

	for(int i = 2 ; i <= n ; i++){
		long newb = olds;
		long news = olds + oldb;

		oldb = newb;
		olds = news;
	}
	long totalways = olds + oldb;
	cout << totalways * totalways;
}