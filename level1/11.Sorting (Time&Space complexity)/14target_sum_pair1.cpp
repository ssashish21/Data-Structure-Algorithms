#include<bits/stdc++.h>
using namespace std;

void targetSum(int *ar, int target , int size){
    //c++ stl sort
    //hybrid of quick , heap , insertion
    //name : introsort
    sort(ar, ar + size); 
    int i = 0, j = size - 1;

    while(i < j){
        int sum = ar[i] + ar[j];

        if(sum == target){
            cout<<ar[i++]<<", "<<ar[j--]<<endl;
        } else if(sum > target){
            j--;
        } else{ 
            i++;
        }
    }
}

int32_t main(){
    int n , target;
    cin>>n;

    int *ar = new int[n];
    for(int i = 0 ; i < n ; i++)
        cin>>ar[i];

    cin>>target;

    targetSum(ar , target , n);

    delete [] ar;
    return 0;
}