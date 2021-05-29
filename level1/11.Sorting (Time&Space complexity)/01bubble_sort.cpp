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


//In each i loop move maximum element to the last
//finally whole array will be sorted
void bubbleSort(int *ar , int size){
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = 0 ; j < size - i - 1 ; j++){
            if(isSmaller(ar , j + 1 , j))
                swap(ar , j + 1 , j);
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

    bubbleSort(ar , n);
    print(ar , n);
}