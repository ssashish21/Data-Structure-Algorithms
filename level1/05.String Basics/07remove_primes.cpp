#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
	for(int i = 2 ; i * i <= n ;i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;

	vector<int> ar(n);
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}		

	for(int i = n -1 ; i >= 0 ; i--){
		if(isprime(ar[i]))
			ar.erase(ar.begin() + i);
	}

	cout << "[";
	for(int i = 0 ; i < ar.size() ; i++){
		cout << ar[i];
		if(i != ar.size()-1)
			cout <<", ";
	}
	cout << "]";
}