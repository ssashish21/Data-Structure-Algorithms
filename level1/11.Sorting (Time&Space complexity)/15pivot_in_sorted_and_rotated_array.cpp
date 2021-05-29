#include<bits/stdc++.h>
using namespace std;

int pivotElement(int *ar,int size){
    int lo = 0 , hi = size - 1;
    
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
      
        if(ar[mid] < ar[hi])
             hi = mid;
        else
             lo = mid + 1;
    }
    
    return ar[lo];
}

int32_t main(){
    int n;
    cin>>n;

    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++) cin>>ar[i];

    cout<<pivotElement(ar , n)<<endl;
    
    delete [] ar;
    return 0;
}