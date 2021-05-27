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

	int x;
	cin >> x;

	int i = 0;
	int j = n - 1;

	while(i < n & j >= 0){
		if(x == ar[i][j]){
			cout <<i<<endl<<j;
			return 0;
		} else if(x < ar[i][j]){
			j--;
		} else {
			i++;
		}
	}
	cout << "Not Found";
}