#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){
    if(idx  == n) return -1;
    
    int max_in_rest = max(arr , idx + 1 , n);
    
    if(arr[idx] > max_in_rest){
        return arr[idx];
    } else {
        return max_in_rest;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
