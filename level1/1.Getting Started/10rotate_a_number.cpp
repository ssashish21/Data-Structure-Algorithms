#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n , k;
	cin >> n >> k;

	int size = log10(n) + 1;
	k = k % size;

	int divs = 0;
	int mult = 0;

	if(k < 0){
		divs = pow(10 , size + k);
		mult = pow(10 , abs(k));
	} else {
		divs = pow(10 , k);
		mult = pow(10 , size - k);
	}

	int res = (n % divs) * mult + (n / divs);
	cout <<res;
}