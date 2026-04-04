#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: House Robber
// Source: LeetCode
// Pattern: Dynamic Programming (Pick / Skip)

// Approach 1: DP (1-based indexing)
// Time: O(n)
// Space: O(n)

// Idea:
// dp[i] = max money using first i houses
// Choice:
// - Skip current → dp[i-1]
// - Rob current → dp[i-2] + nums[i-1]

class Solution_DP {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        return dp[n];
    }
};


// Approach 2: Space Optimized
// Time: O(n)
// Space: O(1)

class Solution_Optimized {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;

        for(int num : nums){
            int cur = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};


// Key Insight:
// At every step → choose between taking current or skipping it
// Only last two states matter → can optimize space

// Mistake:
// Greedy approach fails because local choice ≠ global optimum