#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    if(idx == -1) return idx;
    if(arr[idx] == x) return idx;
    lastIndex(arr , idx - 1 , x , n);
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, n-1, d, n);
    cout << p << endl;
}
