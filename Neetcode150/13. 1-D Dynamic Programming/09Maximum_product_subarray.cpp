#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Maximum Product Subarray
// Pattern: Dynamic Programming (Kadane Variant)

// Approach:
// Track both max and min product at each step

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++){

            // If current number is negative, swap
            if(nums[i] < 0){
                swap(maxSoFar, minSoFar);
            }

            maxSoFar = max(nums[i], maxSoFar * nums[i]);
            minSoFar = min(nums[i], minSoFar * nums[i]);

            result = max(result, maxSoFar);
        }

        return result;
    }
};


// Key Insight:
// Track both max and min because negative flips sign

// Mistake:
// Using normal Kadane (sum logic) → fails