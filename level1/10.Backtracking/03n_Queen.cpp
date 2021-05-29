#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>

bool isSafe(vii &chess , int row , int col){
	for(int i = row - 1 , j = col ; i >= 0 ; i--){
		if(chess[i][j])
			return false;
	}

	for(int i = row - 1 , j = col - 1 ; i >= 0 && j >= 0; i-- , j--){
		if(chess[i][j])
			return false;
	}
	for(int i = row - 1 , j = col + 1 ; i >= 0 && j < chess.size() ; i-- , j++){
		if(chess[i][j])
			return false;
	}
	return true;
}

void Nqueen(vii chess , string qsf , int row){
	if(row == chess.size()){
		cout << qsf <<"."<< endl;
		return;
	}

	for(int col = 0 ; col < chess.size() ; col++){
		if(isSafe(chess , row , col)){
			chess[row][col] = 1;
			Nqueen(chess , qsf + to_string(row) + "-" + to_string(col) + ", " , row + 1);
			chess[row][col] = 0;
		}
	}
}

int main(){
	int n;
	cin >> n;
	vii chess(n , vector<int>(n , 0));

	Nqueen(chess , "" , 0);
} 