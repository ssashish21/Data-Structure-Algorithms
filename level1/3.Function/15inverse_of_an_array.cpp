#include<iostream>
using namespace std;

int* inverse(int* arr, int n){
    // write your code here
    int *res = new int[n];
    for(int i = 0 ; i < n ; i++){
        res[arr[i]] = i;
    }
    return res;
}

void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    
    int* inv = inverse(arr,n);
    display(inv,n);
    
}