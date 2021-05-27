#include<bits/stdc++.h>
using namespace std;
#define ll  long long

int main(){
	int n;
	cin >> n;

	int ar[n][n];

	//take input
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> ar[i][j];
		}
	}

	for(int g = 0 ; g < n ; g++){
		for(int i = 0 , j = g ; j < n ; i++ , j++){
			cout << ar[i][j] <<endl;
		}
	}
	
}