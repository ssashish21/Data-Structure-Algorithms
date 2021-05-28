#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	for(auto &ch : s){
		if(ch >= 'a' && ch <= 'z'){
			ch = 'A' + ch - 'a';
		} else {
			ch = 'a' + ch - 'A';
		}
	}
	cout << s ;
}