#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int a , b , c;
	cin >> a >> b >> c;

	int mx = max({a , b , c});
	bool ok;
	if(a == mx){
		ok = a*a == b*b + c*c;
	} else if(b == mx){
		ok = b*b == a*a + c*c;
	} else {
		ok = c*c == a*a + b*b;
	}
	string res = (ok) ? "true" : "false";
	cout <<res;
}