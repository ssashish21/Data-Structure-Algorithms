#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;

	// int c = 0;
	// while(n){
	// 	n = n / 10;
	// 	c++;
	// }	
	// cout << c;


	//without modifying the number using log
	int count_digit = log10(n) + 1;
	cout << count_digit;
}