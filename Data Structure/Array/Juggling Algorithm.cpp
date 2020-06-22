//Algorithm for array rotation in O(n) time and O(1) time

#include<bits/stdc++.h>
using namespace std;

void leftRotation(vector<int> &arr, int d){
    int n = arr.size();
    d = d % n;
    int gcd = __gcd(d,n);
    for(int i = 0; i < gcd; i++){
        int temp = arr[i];
        int j = i;
        while(1){
            int k = j + d;
            if(k >= n)
                k = k - n;
            if(k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
void printArray(vector<int> &arr){
    for(int i = 0; i < arr.size() ; i++) cout<<arr[i]<<" ";
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12};
    int d = 4;
    leftRotation(arr,d);
    printArray(arr);

    return 0;
}