#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;

	int ar[n][n];

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> ar[i][j];
		}
	}	

	//transpose
	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			int temp = ar[i][j];
			ar[i][j] = ar[j][i];
			ar[j][i] = temp;
		}
	}

	//reverse array col wise
	for(int i = 0 ; i < n ; i++){
		int low = 0 , high = n-1;
		while(low < high){
			int temp = ar[i][low];
			ar[i][low] = ar[i][high];
			ar[i][high] = temp;
			low++;
			high--;
		}
	}
	
	//print rotated array
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	
}