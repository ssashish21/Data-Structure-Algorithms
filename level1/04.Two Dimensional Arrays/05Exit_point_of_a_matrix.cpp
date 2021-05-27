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

	int dir = 0; //0 - e , 1 - s , 2 - w , 3 - n
	int i = 0;
	int j = 0;

	while(1){
		dir = (dir + ar[i][j]) % 4;

		if(dir == 0){ // east
			j++;
		} else if(dir == 1){ // south
			i++;
		} else if(dir == 2){ // west
			j--;
		} else{ // north
			i--;
		}

		if(i < 0){
			i++;
			break;
		} else if(j < 0){
			j++;
			break;
		} else if(i == r){
			i--;
			break;
		} else if(j == c){
			j--;
			break;
		}
	}	

	cout << i << endl << j;
	
}