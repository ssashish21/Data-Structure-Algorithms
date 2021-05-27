#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int base , n1 , n2;
	cin >> base >> n1 >> n2;

	int sum = 0 , p = 1 , carry = 0;
	while(n1 || n2 || carry){
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

	cout <<sum;
}