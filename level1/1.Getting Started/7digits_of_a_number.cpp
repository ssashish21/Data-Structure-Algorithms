#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;
	 
	int cod = log10(n) + 1; // count of dig

	int div = pow(10 , cod - 1);
	while(div != 0){
		cout << n / div << endl;
		n %= div;
		div /= 10;
	}		
}