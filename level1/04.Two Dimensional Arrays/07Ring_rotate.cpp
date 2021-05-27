#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define vii vector<vector<int>>
#define vi  vector<int>

void reverse(vi &oned , int l , int r){
	while(l < r){
		swap(oned[l] , oned[r]);
		l++;
		r--;
	}
}

void rotate(vi &oned , int r){
	r = r % (int)oned.size();
	if(r < 0) r = r + (int)oned.size();

	reverse(oned, 0 , oned.size() - r - 1);
	reverse(oned, oned.size() - r , oned.size() - 1);
	reverse(oned, 0 , oned.size() - 1);
}

vi fillOnedFromShell(vii &ar , int s){
	int minr = s-1;
	int minc = s-1;
	int maxr = ar.size() - s;
	int maxc = ar[0].size() - s;

	int sz = 2 * (maxr - minr + maxc - minc);
	vi oned(sz, 0);

	int idx = 0;

	//lw
	for(int i = minr , j = minc ; i <= maxr ; i++){
		oned[idx++] = ar[i][j];
	}
	//bw
	for(int i = maxr , j = minc + 1 ; j <= maxc ; j++){
		oned[idx++] = ar[i][j];
	}
	//rw 
	for(int i = maxr - 1 , j = maxc ; i >= minr ; i--){
		oned[idx++] = ar[i][j];
	}
	//tw
	for(int i = minr , j = maxc - 1 ; j >= minc + 1 ; j--){
		oned[idx++] = ar[i][j];
	}

	return oned;
}

void fillShellFromOned(vii &ar , int s  , vi &oned){
	int minr = s-1;
	int minc = s-1;
	int maxr = ar.size() - s;
	int maxc = ar[0].size() - s;
	int idx = 0;

	//lw
	for(int i = minr , j = minc ; i <= maxr ; i++){
		ar[i][j] = oned[idx++];
	}
	//bw
	for(int i = maxr , j = minc + 1 ; j <= maxc ; j++){
		ar[i][j] = oned[idx++];
	}
	//rw 
	for(int i = maxr - 1 , j = maxc ; i >= minr ; i--){
		ar[i][j] = oned[idx++];
	}
	//tw
	for(int i = minr , j = maxc - 1 ; j >= minc + 1 ; j--){
		ar[i][j] = oned[idx++];
	}
}

void rotateShell(vii &ar , int s , int r){
	vi oned = fillOnedFromShell(ar , s);
	rotate(oned , r);
	fillShellFromOned(ar , s , oned);
}

void display(vii &ar){
	for(int i = 0 ; i < ar.size(); i++){
		for(int j = 0 ; j < ar[i].size() ; j++){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int row , col;
	cin >> row >> col;

	vii ar(row , vi(col , 0));

	//take input
	for(int i = 0 ; i < row; i++){
		for(int j = 0 ; j < col ; j++){
			cin >> ar[i][j];
		}
	}

	int s , r;
	cin >> s >> r;

	rotateShell(ar , s , r);
	display(ar);
	
}