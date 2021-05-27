#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    
    int first = -1;
    int last = -1;

    //find the first
    int l = 0 , h = n - 1;
    while(l <= h){
    	int m = l + (h-l)/2;
    	if(data < arr[m]){
    		h = m - 1;
    	} else if(data > arr[m]){
    		l = m + 1;
    	} else {
    		first = m;
    		h = m - 1;
    	}
    }

    //find the last
    l = 0 , h = n - 1;
    while(l <= h){
    	int m = l + (h-l)/2;
    	if(data < arr[m]){
    		h = m - 1;
    	} else if(data > arr[m]){
    		l = m + 1;
    	} else {
    		last = m;
    		l = m + 1;
    	}
    }

    cout <<first<<endl<<last;
    
}