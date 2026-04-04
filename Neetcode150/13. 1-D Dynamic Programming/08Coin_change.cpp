#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Coin Change
// Source: LeetCode
// Pattern: Dynamic Programming (Unbounded Knapsack)

// Approach: Bottom-Up DP
// Time: O(n * amount)
// Space: O(amount)

// Idea:
// dp[i] = minimum coins required to make amount i
// For each coin, try to update dp[i]

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;

        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};


// Key Insight:
// This is an unbounded knapsack problem (can use coins multiple times)

// Mistake:
// Using greedy (fails for cases like [1,3,4], amount = 6)