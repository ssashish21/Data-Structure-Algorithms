#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	int a = 0, ab = 0, abc = 0;
	
	for(auto ch : s){
		if(ch == 'a') a = 2 * a + 1;
		if(ch == 'b') ab = 2 * ab + a;
		if(ch == 'c') abc = 2 * abc + ab;
	}
	cout <<abc;
}