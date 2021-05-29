//kth order

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
int quickSelect(int *ar , int lo , int hi , int k){
    int pivot = ar[hi];
    int pi = partition(ar , pivot , lo , hi);

    if(pi < k){
        return quickSelect(ar , pi + 1 , hi , k);
    } else if (pi > k){
        return quickSelect(ar , lo , pi - 1 , k);
    } else {
        return ar[pi];
    }
}

int main(){
    int n; cin>>n;
    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++) cin>>ar[i];
    int k; cin>>k;
    cout<<quickSelect(ar, 0, n - 1 , k - 1);
    delete []ar;
    return 0;
}