#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n , k;
	cin >> n >> k;

	int count = 0;
	while(n){
		int lastnum = n % 10;
		if(k == lastnum) count++;
		n /= 10;
	}	
	cout << count;
}