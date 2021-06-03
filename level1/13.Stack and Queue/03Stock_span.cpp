#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;

	int ar[n];
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}	

	int span[n];
	span[0] = 1;

	stack<int> st;
	st.push(0);

	for(int i = 1 ; i < n ; i++){
		while(st.size() > 0 && ar[i] > ar[st.top()])
			st.pop();

		span[i] = st.empty() ? i + 1 : i - st.top();
		st.push(i);
	}

	for(int i = 0 ; i < n ; i++){
		cout << span[i]<<endl;
	}
}