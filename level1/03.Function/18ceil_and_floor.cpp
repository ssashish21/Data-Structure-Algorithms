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
    
    int ceil = -1;
    int floor = -1;

    int low = 0 , high = n - 1;
    while(low <= high){
    	int mid = low + (high-low)/2;
    	if(data < arr[mid]){
    		ceil = arr[mid]; // this may be ceil
    		high = mid - 1;  // but we have to chk further
    	} else if(data > arr[mid]){
    		floor = arr[mid];
    		low = mid + 1;
    	} else {
    		ceil = arr[mid];
    		floor = arr[mid];
    		break;
    	}
    }

    
    cout <<ceil<<endl<<floor;
    
}