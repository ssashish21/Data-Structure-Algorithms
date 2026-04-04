#include <vector>
#include <algorithm>
using namespace std;

// Problem: Min Cost Climbing Stairs
// Pattern: Dynamic Programming

// Approach: Bottom-Up DP
// Time: O(n)
// Space: O(n)

// Idea:
// To reach step i, we can come from:
// - i-1 (pay cost[i-1])
// - i-2 (pay cost[i-2])


class Solution_DP {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i <= n; i++){
            dp[i] = min(cost[i-1] + dp[i-1],
                        cost[i-2] + dp[i-2]);
        }
        return dp[n];
    }
};


// Approach 2: Space Optimized
// Time: O(n)
// Space: O(1)

class Solution_Optimized {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i <= cost.size(); i++){
            int cur = min(cost[i-1] + prev1,
                          cost[i-2] + prev2);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};