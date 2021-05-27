#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int b , n1 , n2;
	cin >> b >> n1 >> n2;

	int res = 0;
	int p = 1 , c = 0;
	while(n2){	
		int d1 = n1 % 10;
		int d2 = n2 % 10;

		int d = 0;
		d2 = d2 + c;
		if(d2 >= d1){
			d = d2 - d1;
			c = 0;
		} else {
			c = -1;
			d = d2 + b - d1;
		}
		res += d * p;
		p = p * 10;
		n1/=10;
		n2/=10;

	}	
	cout <<res;
}