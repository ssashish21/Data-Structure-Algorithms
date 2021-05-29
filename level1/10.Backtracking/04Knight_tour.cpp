#include<bits/stdc++.h>
using namespace std;
#define vii  vector<vector<int>> 

void display(vii &chess){
	for(int i = 0 ; i < chess.size() ; i++){
		for(int j = 0 ; j < chess[0].size() ; j++){
			cout << chess[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void knightTour(vii &chess , int r , int c , int move){
	if(r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] != 0){
		return;
	}
	if(move == chess.size() * chess.size()){
		chess[r][c] = move;
		display(chess);
		chess[r][c] = 0;
	}

	chess[r][c] = move;
	knightTour(chess , r - 2 , c + 1 , move + 1);
	knightTour(chess , r - 1 , c + 2 , move + 1);
	knightTour(chess , r + 1 , c + 2 , move + 1);
	knightTour(chess , r + 2 , c + 1 , move + 1);

	knightTour(chess , r + 2 , c - 1 , move + 1);
	knightTour(chess , r + 1 , c - 2 , move + 1);
	knightTour(chess , r - 1 , c - 2 , move + 1);
	knightTour(chess , r - 2 , c - 1 , move + 1);
	chess[r][c] = 0;
}


int main(){
	int n , r , c;
	cin >> n >> r >> c;
	int move = 1;
	vii chess(n , vector<int>(n , 0));
	knightTour(chess , r , c , move);
}