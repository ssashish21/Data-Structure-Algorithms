#include<iostream>
using namespace std;

void merge(int ar[] , int si , int mi , int ei){
    int i , j , k;

    int l1 = mi - si + 1;
    int l2 = ei - mi;

    int L[l1] , R[l2];

    cout<<"Merging these two arrays"<<endl;
    for(i = 0 ; i < l1 ; i++)  L[i] = ar[i + si];
    for(i = 0 ; i < l2 ; i++)  R[i] = ar[i + mi + 1];

    cout<<"left array -> ";
    for(i = 0 ; i < l1 ; i++) cout<<L[i]<<" ";
    cout<<endl;

    cout<<"right array -> ";
    for(i = 0 ; i < l2 ; i++) cout<<R[i]<<" ";
    cout<<endl;

    i = 0  , j = 0, k = si;

    while(i < l1 && j < l2){
        if(L[i] <= R[j])
            ar[k++] = L[i++];
        else 
            ar[k++] = R[j++];
    }

    while(i < l1) ar[k++] = L[i++];
    while(j < l2) ar[k++] = R[j++];
}

void mergeSort(int ar[] , int startIndex , int endIndex){ 
    if(startIndex >= endIndex) return;// base case if(only one element or zero element)
 
    int middleIndex = startIndex + (endIndex - startIndex) / 2;

    mergeSort(ar , startIndex , middleIndex);      // merge sort in first half
    mergeSort(ar , middleIndex+ 1 , endIndex);     // merge sort in second half
    merge(ar, startIndex , middleIndex , endIndex);// merge two sorted array
}

int main(){
    int n; cin>>n;
    int ar[n];
    for(int i = 0 ; i < n ; i++){
        cin>>ar[i];
    }
    mergeSort(ar, 0 , n-1);

    cout<<"Sorted Array -> ";
    for(int i = 0 ; i < n; i++){
        cout<<ar[i]<<" ";
    }
}