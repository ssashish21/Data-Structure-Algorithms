#include<bits/stdc++.h>
using namespace std;

void print(int *ans, int size){
    for(int i = 0 ; i < size ; i++)
        cout<<ans[i]<<endl;
}

//stable sorting algorithm
void countSort(int *ar , int mn , int mx , int size){
    int range = mx - mn + 1;

    int *freq = new int[range];

    //count frequency
    for(int i = 0 ; i < size ; i++)
        freq[ar[i] - mn]++;

    //prefix sum
    for(int i = 1 ; i < range ; i++) 
        freq[i] = freq[i] + freq[i - 1];

    int *ans = new int[size];
    //maintain the order
    for(int i = size - 1 ; i >= 0 ; i--){
        ans[freq[ar[i] - mn] - 1] = ar[i];
        freq[ar[i] - mn]--; 
    }
    print(ans , size);
    delete [] ans;
}
int main(){
    int n ;
    cin>>n;

    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin>>ar[i];
    }

    int mn = *min_element(ar , ar + n);
    int mx = *max_element(ar , ar + n);

    countSort(ar, mn , mx , n);
    
    delete [] ar;
    return 0;
}