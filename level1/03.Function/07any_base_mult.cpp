#include<bits/stdc++.h>
using namespace std;
#define ll long long


int mult(int num , int d2 , int b){
	int m = 0 , c = 0 , p = 1;
	while(num > 0 || c > 0){
		int d1 = num % 10;
		num/=10;

		int d = (d1 * d2) + c;
		c = d / b;
		d = d % b;

		m = m + d * p;
		p = p * 10;
	}
	// cout<<m<<endl;
	return m;
}

int add(int base , int n1 , int n2){
	int sum = 0 , p = 1 , carry = 0;
	while(n1 > 0 || n2 > 0 || carry > 0){
		int rm1 = n1 % 10;
		int rm2 = n2 % 10;

		int add = carry + rm1 + rm2;
		int dig = add % base;
		carry = add / base;

		sum += dig * p;
		p = p * 10;
		n1/=10;
		n2/=10;
	}

	return sum;
}

int main(){
	int b , n1 , n2;
	cin >> b >> n1 >> n2;


	int res = 0 , p = 1;
	while(n2 > 0){
		int d2 = n2%10;
		n2/=10;

		int sp = mult(n1 , d2 , b) * p;
		res = add(b , res , sp);

		p = p * 10;
	}	
	cout<<res;
}
//1200100



