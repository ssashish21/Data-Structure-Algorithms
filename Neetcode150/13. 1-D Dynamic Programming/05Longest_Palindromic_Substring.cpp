#include <iostream>
#include <string>
using namespace std;

// Problem: Longest Palindromic Substring
// Pattern: Expand Around Center

// Approach:
// For each index, expand for:
// 1. Odd length palindrome (i, i)
// 2. Even length palindrome (i, i+1)

// Time: O(n^2)
// Space: O(1)

class Solution {
private:
    string expand(string &s, int l, int r){
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";

        for(int i = 0; i < n; i++){
            string odd = expand(s, i, i);
            string even = expand(s, i, i + 1);

            if(odd.size() > res.size()) res = odd;
            if(even.size() > res.size()) res = even;
        }

        return res;
    }
};


// Key Insight:
// A palindrome expands from its center

// Mistake:
// Trying brute force substrings → O(n^3)