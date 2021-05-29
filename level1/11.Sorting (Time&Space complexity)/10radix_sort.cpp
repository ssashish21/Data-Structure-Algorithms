#include<bits/stdc++.h>
using namespace std;

void print(int *ans, int size){
    for(int i = 0 ; i < size ; i++) 
        cout<<ans[i]<<" ";
    cout<<endl;
}

void countSort(int *ar ,int exp ,int size){
    int *ans = new int[size];
    int *freq = new int[10];

    for(int i = 0 ; i < size ; i++)
        freq[(ar[i] / exp) % 10]++;

    for(int i = 1 ; i < 10 ; i++)
        freq[i] += freq[i - 1];

    for(int i = size -1; i >= 0 ; i--){
        int pos = freq[(ar[i] / exp) % 10] - 1;
        ans[pos] = ar[i];
        freq[(ar[i]/exp)%10]--; 
    }

    for(int i = 0 ; i < size ; i++) 
        ar[i] = ans[i];

    cout<<"After sorting on "<<exp<<" place -> ";
    print(ar , size);
    delete [] ans;
}

void radixSort(int *ar , int size){
    int maxVal = *max_element(ar , ar + size);
    int exp = 1;

    while(maxVal / exp > 0){
        countSort(ar , exp , size);
        exp  = exp * 10;
    }
}
int main(){
    int n;
    cin>>n;
    int *ar = new int[n];

    for(int i = 0 ; i < n ; i++)
        cin>>ar[i];

    radixSort(ar, n);
    print(ar , n);

    delete [] ar;
    return 0;
}

/*
First sort all the number according to the once place,
then tens , then hundred place and so on finally the 
resultant array we get will be sorted.
*/
