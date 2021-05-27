#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}	

	int row = *max_element(ar , ar + n);
	for(int i = 1 ; i <= row ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i <= row - ar[j-1])
				cout << "\t";
			else
				cout <<"*\t";
		}
		cout<<endl;
	}
}