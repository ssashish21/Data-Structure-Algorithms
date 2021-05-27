#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;

	int a = 0 , b = 1 , c;
	for(int i = 0 ; i < n ; i++){
		cout << a << endl;
		c = a + b;
		a = b;
		b = c;
	}	
}