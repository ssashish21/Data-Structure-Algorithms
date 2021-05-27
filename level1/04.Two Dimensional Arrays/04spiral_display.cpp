#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int r , c;
	cin >> r >> c;

	int ar[r][c];

	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> ar[i][j];
		}
	}	


	int minr = 0;
	int minc = 0;

	int maxr = r - 1;
	int maxc = c - 1;

	int total = r * c;

	while(1){
		//left wall
		for(int i = minr , j = minc ; i <= maxr ; i++){
			cout << ar[i][j] << endl;
			total--;
		}
		minc++;
		if(total == 0) break;
		//bottom wall
		for(int i = maxr , j = minc ; j <= maxc ; j++){
			cout << ar[i][j] << endl;
			total--;
		}
		maxr--;
		if(total == 0) break;
		//right wall
		for(int i = maxr , j = maxc ; i >= minr ; i--){
			cout << ar[i][j] << endl;
			total--;
		}
		maxc--;
		if(total == 0) break;
		//top wall
		for(int i = minr , j = maxc ; j >= minc ; j--){
			cout << ar[i][j] << endl;
			total--;
		}
		minr++;
		if(total == 0) break;
	}	
}