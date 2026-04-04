#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem: Count Palindromic Substrings
// Pattern: Dynamic Programming (Gap Strategy)

// Approach:
// dp[i][j] = true if substring s[i..j] is palindrome

// Time: O(n^2)
// Space: O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++){

                if(gap == 0){
                    dp[i][j] = true;
                }
                else if(gap == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]) count++;
            }
        }

        return count;
    }
};


// Key Insight:
// A substring is palindrome if:
// - Ends match AND
// - Inner substring is palindrome

// Mistake:
// Trying brute force → O(n^3)