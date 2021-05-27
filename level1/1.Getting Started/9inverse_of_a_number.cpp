#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;
	int p = 1 , res = 0;
	while(n){
		int dig = n % 10;
		res += p * pow(10 , dig-1);
		p++;
		n /= 10;
	}	
	cout<<res;
}