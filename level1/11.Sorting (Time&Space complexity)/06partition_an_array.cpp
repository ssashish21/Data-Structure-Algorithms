#include<iostream>
using namespace std;

void swap(int *ar , int i , int j){
    cout<<"Swapping "<<ar[i]<<" and "<<ar[j]<<endl;
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

//0 to j- less than or equal to pivot
//j to i- greater than pivot
//i to (size - 1)- unknown elements

void partitionArray(int *ar , int size , int pivot){
    int i = 0 , j = 0;
    while(i < size){
        if(ar[i] > pivot){
            i++;
        } else {
            swap(ar , i , j);
            i++;
            j++;
        }
    }
}


void print(int *ar , int size){
    for(int i = 0 ; i < size; i++){
        cout<<ar[i]<<" ";
    }
}


int main(){
    int n , pi;
    cin>>n;

    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++) 
        cin>>ar[i];
    
    cin>>pi;

    partitionArray(ar, n , pi);
    print(ar , n);

    delete []ar;
    return 0;
}