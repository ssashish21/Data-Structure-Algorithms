#include<bits/stdc++.h>
using namespace std;

int fact(int n){
	int f = 1;
	for(int i = 2 ; i <= n ; i++){
		f *= i;
	}
	return f;
}

int main(){
	string s;
	cin >> s;

	int n = s.length();
	int f = fact(n);

	for(int i = 0 ; i < f ; i++){
		string str = s;
		int temp = i;

		for(int div = n ; div >= 1 ; div--){
			int q = temp / div;
			int r = temp % div;

			cout << str[r];
			str.erase(str.begin() + r);

			temp = q;
		}
		cout << endl;
	}
}