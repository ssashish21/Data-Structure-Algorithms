#include<bits/stdc++.h>
using namespace std;
#define ll long long

int euclidean_gcd(int a , int b){
	if(b == 0) return a;
	return euclidean_gcd(b , a % b);
}

int gcd(int a , int b){
	while(b % a != 0){
		int r = b % a;
		b = a;
		a = r;
	}
	return a;
}

int main(){
	int a , b;
	cin >> a >> b;
	int g = euclidean_gcd(a , b);
	int l = (a * b) / g;
	cout <<g<<endl<<l;	
}