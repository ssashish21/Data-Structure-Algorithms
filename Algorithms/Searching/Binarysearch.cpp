Binary Search: searching algorithm(Only perform in sorted sequence) in O(logN) time
There are a lot of variations of binary search
1. Simple Binary search(itterative)
2. Recursive Binary Search
3. First occurrence of a number in sorted array
4. Last Occurrence of a number in sorted array
5. Search Element in a sotted and rotated array
6. count the number of rotation of a sorted and rotated array

#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> &arr,int key){
    int low = 0;
    int high = arr.size()-1;
    
    while(low <= high){
        int mid = low + (high - low) / 2; // For Handeling overflow situation 
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;      //Element not present in the array
}


/* Recursive Method */

int binarySearch(vector<int> &arr, int low, int high, int key){
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) return binarySearch(arr,low,mid-1,key);
        else return binarySearch(arr,mid+1,high,key);
    }
    return -1;
}

/* Other variations
 1.First Occurence of a number */
 
int lowerBound(vector<int> &arr, int num){
    int low = 0;
    int high = arr.size() - 1;
    int result = -1,mid;
    while(low <= high){
        mid = low = (high - low) / 2;
        if(arr[mid] == num)
        {
            result = mid;
            high = mid - 1; // when num is found further cheack in left 
        }
        else if(arr[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}


// 2.Last Occurence of a number

int UpperBound(vector<int> &arr, int num){
    int low = 0;
    int high = arr.size() - 1;
    int result = -1,mid;
    while(low <= high){
        mid = low = (high - low) / 2;
        if(arr[mid] == num)
        {
            result = mid;
            low = mid + 1;   //when number is found cheack in left
        }
        else if(arr[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

// 3.Search an element in a sorted and rotated array
//{4,5,6,7,8,9,1,2,3}
int Search(vector<int> &arr, int key){
	int low = 0,mid,high = arr.size() - 1;
	while(low <= high){
		mid = low + (high - low ) / 2;
		if(arr[mid] == key) return mid;
		else if(arr[low] <= arr[mid]) // left subarray is sorted
		{
			if(key >= arr[low] && key <= arr[mid]) // key element is in sorted subarray
				high = mid - 1;
			else								   // key element is in unsorted subarray
				low = mid + 1;
		}
		else
		{
			if(key >=arr[mid] && key <= arr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}

//4.Minimum Element in a sorted and rotated array
//key idea: The prev and next value of the minimum element is greater
//If there is no prev value then the array is not rotated
//Index number of minimum element is count of rotation of that array

int minimumElement(vector<int> &arr, int low,int high){
	if(arr.size() == 1) return arr[0];
	int low = 0;
	int high = arr.size() - 1;
	if(arr[0] < arr[high]) //No rotation
	   return arr[0];
	while(low<=high){
		int  mid = low + (high - low) / 2;
		if(arr[mid] < arr[mid+1] && start < mid) return arr[mid];
		else if(arr[mid] > arr[mid+1] && end > mid) return arr[mid+1];
		else if(arr[mid] < arr[end]) high = mid - 1;
		else low = mid + 1;
	}
	return - 1;
}



int main(){
	vector<int> arr={1,2,3,4,9,12,16,22,30};
// 	cout<<binarySearch(arr,16);
	cout<<binarySearch(arr,0,arr.size()-1,16);
	return 0;
}