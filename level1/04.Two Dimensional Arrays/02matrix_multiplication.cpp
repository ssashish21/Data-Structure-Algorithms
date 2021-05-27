#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int r1 , c1 , r2 , c2;
	cin >> r1 >> c1;

	int ar[r1][c1];
	for(int i = 0 ; i < r1 ; i++){
		for(int j = 0 ; j < c1 ; j++){
			cin >> ar[i][j];
		}
	}

	cin >> r2 >> c2;
	int br[r2][c2];
	for(int i = 0 ; i < r2 ; i++){
		for(int j = 0 ; j < c2 ; j++){
			cin >> br[i][j];
		}
	}	

	if(c1 != r2){
		cout << "Invalid input";
		return 0;
	}

	int cr[r1][c2];
	for(int i = 0 ; i < r1 ; i++){
		for(int j = 0 ; j < c2 ; j++){
			int res = 0;
			for(int k = 0 ; k < c1 ; k++)
				res += (ar[i][k] * br[k][j]);
			cr[i][j] = res;
		}
	}

	for(int i = 0 ; i < r1 ; i++){
		for(int j = 0 ; j < c2 ; j++){
			cout << cr[i][j] << " ";
		}
		cout << endl;
	}
}