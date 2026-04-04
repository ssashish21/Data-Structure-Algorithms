#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Problem: Partition Equal Subset Sum
// Pattern: 0/1 Knapsack (Subset Sum)

// --------------------------------------------------
// Approach 1: 2D DP
// --------------------------------------------------
// Time: O(n * sum)
// Space: O(n * sum)

// Idea:
// dp[i][j] = can we form sum j using first i elements

class Solution_2D {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2) return false;

        int target = total / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case
        for(int i = 0; i <= n; i++) dp[i][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j]; // not pick
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]]; // pick
                }
            }
        }

        return dp[n][target];
    }
};


// --------------------------------------------------
// Approach 2: 1D DP (Optimized) 🔥
// --------------------------------------------------
// Time: O(n * sum)
// Space: O(sum)

// Idea:
// Collapse 2D → 1D
// Traverse backwards to avoid reuse

class Solution_1D {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2) return false;

        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int num : nums){
            for(int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};


// Key Insight:
// Convert problem → subset sum (target = total / 2)

// Mistake:
// Forward loop in 1D → leads to using same element multiple times