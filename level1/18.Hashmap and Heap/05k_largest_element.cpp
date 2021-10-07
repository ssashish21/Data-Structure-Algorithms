#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , k;
	cin >> n;

	int ar[n];
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i];
	}	
	cin >> k;

	priority_queue<int , vector<int>, greater<int>> pq;
	
	for(int i = 0 ; i < k ; i++){
		pq.push(ar[i]);
	}

	for(int i = k ; i < n ; i++){
		if(pq.top() < ar[i]){
			pq.push(ar[i]);
			pq.pop();
		}
	}

	while(pq.size() > 0){
		cout << pq.top() << endl;
		pq.pop();
	}
}