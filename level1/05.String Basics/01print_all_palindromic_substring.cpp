#include<bits/stdc++.h>
using namespace std;

bool isPalin(string s){
	int i = 0;
	int j = s.length() - 1;
	while(i <= j){
		if(s[i++] != s[j--])
			return false;
	}
	return true;
}

int main(){
	string s;
	cin >> s;

	for(int i = 0 ; i < s.length() ; i++){
		for(int j = 1 ; j <= s.length() - i ; j++){
			string sub = s.substr(i , j);
			if(isPalin(sub)){
				cout << sub << endl;
			}
		}
	}
}