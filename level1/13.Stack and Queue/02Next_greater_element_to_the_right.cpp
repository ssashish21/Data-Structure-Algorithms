#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int ar[n];
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}	

	int ngr[n];
	stack<int> st;

	for(int i = n-1 ; i >= 0 ; i--){
		while(st.size() > 0 && ar[i] > st.top())
			st.pop();

		ngr[i] = st.empty() ? -1 : st.top();

		st.push(ar[i]);
	}

	for(int i = 0 ; i < n ; i++){
		cout << ngr[i] << "\n";
	}
}

/*
1. Next greater element to the right
2. Next smaller element to the right
3. Next greater element to the left
4. Next smaller element to the left
*/