#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Intervals{
	int start;
	int end;
};

bool cmp(Intervals a , Intervals b){
	return a.start < b.start;
}


void MergeIntervals(vector<Intervals> ar){
	sort(ar.begin(), ar.end() , cmp);

	deque<Intervals> st;
	st.push_back(ar[0]);

	for(int i = 1 ; i < ar.size() ; i++){
		Intervals &prev = st.back();

		if(ar[i].start > prev.end){
			st.push_back(ar[i]);
		} else {
			prev.end = max(prev.end , ar[i].end);
		}
	}

	for(auto it : st){
		cout << it.start << " " << it.end << endl;
	}
}


int main(){
	int n;
	cin >> n;

	vector<Intervals> ar(n);
	for(int i = 0 ; i < n ; i++){
		cin >> ar[i].start;
		cin >> ar[i].end;
	} 

	MergeIntervals(ar);
}