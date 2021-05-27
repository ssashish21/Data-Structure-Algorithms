#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >>n;
	int ar[n];
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}	

	int mx = INT_MIN;
	int mn = INT_MAX;
	for(int i = 0 ; i < n ; i++){
		mx = max(mx , ar[i]);
		mn = min(mn , ar[i]);
	}
	cout << mx - mn;
}