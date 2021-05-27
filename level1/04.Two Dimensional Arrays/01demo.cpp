#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int r , c;
	cin >> r >> c;

	int ar[r][c]; // create 2d array

	//take input
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> ar[i][j];
		}
	}	

	//print output
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}