//count number of binary string which have no consecutive 0's of size n

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int old0 = 1;
	int old1 = 1;

	for(int i = 2 ; i <= n ; i++){
		int new0 = old1;
		int new1 = old1 + old0;

		old0 = new0;
		old1 = new1;
	}
	cout << old0 + old1;
}

// old0 -> bs ends by 0
// old1 -> bs ends by 1