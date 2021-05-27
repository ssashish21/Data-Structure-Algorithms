#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int num , base;
	cin >> num >> base;

	int res = 0 , place = 0;
	while(num){
		int rem = num % base;
		res += rem * pow(10 , place);
		place++;
		num /= base;
	}
	cout <<res;

}