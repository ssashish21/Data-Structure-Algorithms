#include<bits/stdc++.h>
using namespace std;

int climb_stair(int);
int cs(int);

int main(){
	int n;
	cin >> n;
	cout << climb_stair(n);
}

int climb_stair(int n){
	int paths[n+1];
	paths[0] = 1;

	for(int i = 1 ; i <= n ; i++){
		if(i == 1) 
			paths[i] = paths[i-1];
		else if(i == 2)
			paths[i] = paths[i-1] + paths[i-2];
		else
			paths[i] = paths[i-1] + paths[i-2] + paths[i-3];
	}

	return paths[n];
}

int cs(int n){
	int p[n+1];
	p[0] = p[1] = 1;
	p[2] = 2;
	for(int i = 3 ; i <= n ; i++)
		p[i] = p[i-1] + p[i-2] + p[i-3];

	return p[n];
}
