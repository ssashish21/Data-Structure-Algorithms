// Largest contigious Array sum

#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(vector<int> arr){
    int max_sum = arr[0];
    int curr_sum = arr[0];
    
    for(int i = 1 ; i < arr.size() ; i++){
        curr_sum = max(arr[i] , curr_sum + arr[i]);
        max_sum = max(curr_sum , max_sum);
    }
    return max_sum;
}
int main(){
    vector<int> A = {-2,-3,4,-1,-2,1,5,-3};
    
    int max_sum = maxSubArraySum(A);
    
    cout<<max_sum<<"\n";
    
    return 0;
}
