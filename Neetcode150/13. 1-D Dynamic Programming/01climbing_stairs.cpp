class Solution {
public:
    int climbStairs(int n) {
        int dp[n+ 1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        int pp = 1, p = 1;
        for(int i = 2; i <= n; i++){
            int cur = pp + p;
            pp = p;
            p = cur;
        }

        return p;
    }
};