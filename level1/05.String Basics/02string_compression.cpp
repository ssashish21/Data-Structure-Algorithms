#include<bits/stdc++.h>
using namespace std;

string compression1(string s){
	string res(1 , s[0]);
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == s[i-1]){
			continue; 
		} else {
			res += s[i];
		}
	}
	return res;
}

string compression2(string s){
	string res = "";
	int c = 1;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == s[i-1]){
			c += 1;
		} else {
			if(c > 1){
				res += to_string(c);
				c = 1;
			}
			res += s[i];
		}
	}
	if(c > 1){
		res += to_string(c);
		c = 1;
	}
	return res;
}

int main(){
	string s;
	cin >> s;

	cout << compression1(s) << endl;
	cout << compression2(s)	<< endl;
}