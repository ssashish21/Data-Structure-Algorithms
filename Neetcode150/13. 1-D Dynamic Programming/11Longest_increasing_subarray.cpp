#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Longest Increasing Subsequence (LIS)
// Pattern: Dynamic Programming

// --------------------------------------------------
// Approach 1: DP (O(n^2))
// --------------------------------------------------
// Time: O(n^2)
// Space: O(n)

// Idea:
// LIS[i] = length of LIS ending at index i

class Solution_DP {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLIS = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};


// --------------------------------------------------
// Approach 2: Binary Search (O(n log n)) 🔥
// --------------------------------------------------
// Time: O(n log n)
// Space: O(n)

// Idea:
// Maintain a sequence where:
// res[i] = smallest possible tail of LIS of length i+1

class Solution_Optimized {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for(int num : nums){
            auto it = lower_bound(res.begin(), res.end(), num);

            if(it == res.end()){
                res.push_back(num);
            } else {
                *it = num;
            }
        }

        return res.size();
    }
};


// Key Insight:
// DP → build LIS ending at each index
// Binary Search → maintain optimal tails

// Mistake:
// Thinking res[] is actual LIS → it's NOT, only length is valid

//------------------------------------------------------------------------------------------

// Problem: Russian Doll Envelopes
// Pattern: LIS + Sorting Trick

// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // Step 1: Sort
        sort(envelopes.begin(), envelopes.end(),
            [](auto &a, auto &b){
                if(a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
            });

        // Step 2: Apply LIS on heights
        vector<int> res;

        for(auto &e : envelopes){
            int h = e[1];

            auto it = lower_bound(res.begin(), res.end(), h);

            if(it == res.end()){
                res.push_back(h);
            } else {
                *it = h;
            }
        }

        return res.size();
    }
};


// Key Insight:
// Convert 2D problem → 1D LIS using sorting

// Mistake:
// Sorting both width & height ascending → wrong result