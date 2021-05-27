#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int num , base1 , base2;
	cin >> num >> base1 >> base2;

	//convert the number from base1 into base 10
	int numbase10 = 0 , place = 0;
	while(num){
		int rem = num % 10;
		numbase10 += rem * pow(base1 , place);
		place++;
		num /= 10;
	}	

	//convert the number from base 10  to base2
	int res = 0 , p = 1;
	while(numbase10){
		int rem = numbase10 % base2;
		res += rem * p;
		p = p * 10;
		numbase10 /= base2;
	}
	cout <<res;
}