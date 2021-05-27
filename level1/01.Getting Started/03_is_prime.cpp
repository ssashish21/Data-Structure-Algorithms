#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int n){
	for(int i = 2 ; i * i <= n ; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		if(isPrime(n)){
			cout <<"prime\n";
		} else {
			cout <<"not prime\n";
		}
	}	
}