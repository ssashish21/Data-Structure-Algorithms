#include<bits/stdc++.h>
using namespace std;

void swap(int *ar , int i , int j){
    cout << "Swapping index " << i << " and index " << j << endl;
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp; 
}

void sort012(int *ar , int size){
  int i = 0, j = 0 , k = size - 1;
  while(i <= k){
      if(ar[i] == 0){
         swap(ar , i++ , j++);
      } else if(ar[i] == 1){
         i++;
      } else {
        swap(ar , i , k--);
      }
  } 
}


int main(){
    int n;
    cin >> n;

    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin >> ar[i];
    }

    sort012(ar , n);

    for(int i = 0 ; i < n ; i++){
       cout << ar[i] << endl;
    }
    delete [] ar;
}

