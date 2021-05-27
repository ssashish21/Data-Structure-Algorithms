#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;
	for(int p = 2 ; p *p <= n ; p++){
		while(n % p == 0){
			cout << p << " ";
			n /= p;
		}
	}	
	if(n != 0) cout << n; // n must be prime at this time
}