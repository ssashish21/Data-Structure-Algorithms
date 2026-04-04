// Problem: Climbing Stairs
// Pattern: Dynamic Programming (Fibonacci)

// Approach 1: DP Array
// Time: O(n)
// Space: O(n)

class Solution_DP {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


// Approach 2: Space Optimized
// Time: O(n)
// Space: O(1)
// Insight: Only last two states are needed

class Solution_Optimized {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev1 = 1;

        for(int i = 2; i <= n; i++){
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};