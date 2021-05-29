#include<iostream>
using namespace std;
bool isSmaller(int *ar , int i , int j){
    cout<<"Comparing "<<ar[i]<<" and "<<ar[j]<<endl;
    return ar[i] < ar[j];
}

void swap(int *ar , int i , int j){
    cout<<"Swapping "<<ar[i]<<" and "<<ar[j]<<endl;
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

void selectionSort(int *ar , int size){
   for(int i = 0 ; i < size - 1 ; i++){
       int mi = i;
       for(int j = i + 1 ; j < size ; j++){
           if(isSmaller(ar , j , mi))
                mi = j;
       }
       swap(ar , i , mi);
   }
}

void print(int *ar , int size){
    for(int i = 0 ; i < size ; i++){
        cout<<ar[i]<<endl;
    }
}
int main(){
    int n;
    cin >> n;

    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++)
        cin >> ar[i];

    selectionSort(ar , n);
    print(ar , n);
}