// An Array containing only 0's, 1's, 2's Sort the array in O(n) time and O(1) space.
// Input: {0,1,2,2,1,0,0,2,0,1,1,0}
// Output:{0,0,0,0,0,1,1,1,1,2,2,2}

#include<bits/stdc++.h>
using namespace std;

void DNFP(vector<int> &arr){
	int low = 0, mid = 0;
	int high = arr.size() - 1;
	int pivot = 1;
	while(mid <= high){
	    switch (arr[mid]) 
	      {  
		case 0:                            // mid is 0 
		    swap(arr[low++], arr[mid++]);  
		    break;  

		case 1:                           // mid is 1 . 
		    mid++;  
		    break;  

		case 2:                           // mid is 2  
		    swap(arr[mid], arr[high--]);  
		    break;  
	      }  
	}
}

void printArray(vector<int> &A){ for(auto i : A) cout<<i<<" ";}

int main(){
	vector<int> A = {0,1,2,2,1,0,0,2,0,1,1,0};

	DNFP(A);

   	printArray(A);
	return 0;
}
