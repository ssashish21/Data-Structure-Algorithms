#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem: Decode Ways
// Source: LeetCode
// Pattern: Dynamic Programming (Count Ways)

// Approach 1: Top-Down (Memoization)
// Time: O(n)
// Space: O(n)

class Solution_Memo {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;

        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }

private:
    int solve(int i, string &s, vector<int> &dp){
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int res = solve(i + 1, s, dp);

        if(i < s.length() - 1 &&
           ((s[i] == '1') || (s[i] == '2' && s[i+1] <= '6')))
        {
            res += solve(i + 2, s, dp);
        }

        return dp[i] = res;
    }
};


// Approach 2: Bottom-Up DP
// Time: O(n)
// Space: O(n)

class Solution_DP {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0') continue;

            dp[i] = dp[i + 1];

            if(i < n - 1 &&
               ((s[i] == '1') || (s[i] == '2' && s[i+1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};


// Key Insight:
// At each index → take 1 digit or valid 2 digits

// Mistake:
// '0' cannot be decoded alone