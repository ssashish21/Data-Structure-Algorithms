#include<bits/stdc++.h>
using namespace std;
#define ll  long long

int main(){
	int n;
	cin >> n;

	int ar[n][n];

	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> ar[i][j];
		}
	}

	for(int i = 0 ; i < n ; i++){
		int svj = 0;
		for(int j = 0 ; j < n ; j++){
			if(ar[i][j] < ar[i][svj]){
				svj = j;
			}
		}

		bool found = true;
		for(int k = 0 ; k < n ; k++){
			if(ar[k][svj] > ar[i][svj]){
				found = false;
				break;
			}
		}

		if(found){
			cout << ar[i][svj];
			return 0;
		}
	}	
	cout << "Invalid input";
}