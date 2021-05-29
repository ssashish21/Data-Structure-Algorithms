#include<iostream>
using namespace std;

void swap(int *ar , int i , int j){
    cout<<"Swapping "<<ar[i]<<" and "<<ar[j]<<endl;
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

int partition(int *ar , int pivot , int lo ,int hi){
    cout<<"pivot -> "<<pivot<<endl;
    int i = lo , j = lo;
    while(i <= hi){
        if(ar[i] > pivot){
            i++;
        } else {
            swap(ar , i , j);
            i++;
            j++;
        }
    }
    cout<<"pivot index -> "<<(j-1)<<endl;
    return (j-1);
}

void quickSort(int *ar , int lo , int hi){
    if(lo > hi) return;

    int pivot = ar[hi];

    int pi = partition(ar, pivot , lo , hi);
    
    quickSort(ar , lo , pi - 1);
    quickSort(ar , pi + 1 , hi);
}

void print(int *ar , int size){
    for(int i = 0 ; i < size; i++){
        cout<<ar[i]<<" ";
    }
}

int main(){
    int n; cin>>n;
    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++) cin>>ar[i];
    quickSort(ar, 0, n - 1);
    print(ar , n);
    delete []ar;
    return 0;
}