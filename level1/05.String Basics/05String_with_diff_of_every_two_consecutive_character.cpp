#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	string res(1 , s[0]);
	for(int i = 1 ; i < s.size() ; i++){
		char prev = s[i-1];
		char curr = s[i];

		int diff = curr - prev;

		res += to_string(diff);
		res += curr;
	}
	cout<<res;
}