#include<iostream>
using namespace std;

void print(int *ar , int size){
    for(int i = 0 ; i < size ; i++) 
        cout<<ar[i]<<endl;
}

void mergeArray(int *ar1, int *ar2 , int n1 , int n2){
    int *ar = new int[n1 + n2];

    int i = 0 , j = 0 , k = 0;

    while(i < n1 && j < n2){
        if(ar1[i] < ar2[j]) 
            ar[k++] = ar1[i++];
        else
            ar[k++] = ar2[j++];
    }

    while(i < n1) ar[k++] = ar1[i++];
    while(j < n2) ar[k++] = ar2[j++];

    print(ar , k);
}

int main(){
    int n1 , n2;

    cin >> n1;
    int *ar1 = new int[n1];

    for(int i = 0 ; i < n1 ; i++) 
        cin>>ar1[i];

    cin >> n2;
    int *ar2 = new int[n2];

    for(int i = 0 ; i < n2 ; i++)
         cin>>ar2[i];
     
    mergeArray(ar1, ar2 , n1 , n2);
}