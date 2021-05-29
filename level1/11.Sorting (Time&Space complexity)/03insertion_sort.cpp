#include<iostream>
using namespace std;
bool isSmaller(int *ar , int i , int j){
    cout<<"Comparing "<<ar[i]<<" and "<<ar[j]<<endl;
    return ar[i] < ar[j];
}

void swap(int *ar , int i , int j){
    cout<<"Swapping "<<ar[i]<<" and "<<ar[j]<<endl;
    int temp = ar[j];
    ar[j] = ar[i];
    ar[i] = temp;
}

void insertionSort(int *ar , int size){
   for(int i = 1 ; i < size ; i++){
      for(int j = i - 1 ; j >= 0 ; j--){
          if(isSmaller(ar , j + 1 , j))
            swap(ar , j , j + 1);
          else
            break;
      }
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

    insertionSort(ar , n);
    print(ar , n);
}