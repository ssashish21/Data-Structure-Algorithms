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
	for(int j = 0 ; j < c ; j++){
		if(j%2==0){
			for(int i = 0 ; i < r ; i++){
				cout << ar[i][j] <<endl;
			}
		}else{
			for(int i = r-1 ; i >= 0 ; i--){
				cout << ar[i][j] << endl;
			}
		}
	}
}