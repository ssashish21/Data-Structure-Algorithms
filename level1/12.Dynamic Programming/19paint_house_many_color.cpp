#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minInRow(vector<int> &col , int exc){
    int ans = INT_MAX;
    for(int i = 0 ; i < col.size() ; i++){
        if(i != exc){
            ans = min(ans , col[i]);
        }
    }
    return ans;
}

int main(){
    int n , k;
    cin >> n >> k;
    
    vector<int> ar[n];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < k ; j++){
            int temp;
            cin >> temp;
            ar[i].push_back(temp);
        }
    }
    
    vector<int> dp = ar[0];

    for(int i = 1 ; i < n ; i++){
        vector<int> prev_c = dp;

        for(int j = 0 ; j < k ; j++){
            dp[j] = minInRow(prev_c , j) + ar[i][j];
        }
    }

    int ans = dp[0];
    for(int i = 1 ; i < dp.size() ; i++){
        ans = min(ans , dp[i]);
    }

    cout<<ans<<endl;
}