#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int N = 1e6 + 6;
	bool prime[N];
	memset(prime , true , sizeof(prime));

	prime[0] = prime[1] = false;

	for(int i = 2 ; i*i <= N ; i++){
		if(prime[i]){
			for(int j = i * 2 ; j < N ; j+=i){
				prime[j] = false;
			}
		}
	}

	int low , high;
	cin >> low >> high;
	for(int i = low ; i <= high ; i++){
		if(prime[i]) cout << i << endl;
	}
}