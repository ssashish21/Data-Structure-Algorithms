#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Problem: Word Break
// Pattern: Dynamic Programming (String Partition)

// Approach: Bottom-Up DP
// Time: O(n^2)
// Space: O(n)

// Idea:
// dp[i] = true if substring s[0...i-1] can be segmented

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){

                if(dp[j] && dict.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};


// Key Insight:
// Break string into valid prefixes

// Mistake:
// Trying greedy → fails for cases like "catsandog"