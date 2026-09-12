class Solution {
public:

    int climbStairs(int n) {

        // If there is only 1 stair,
        // there is only 1 way
        if(n == 1)
            return 1;

        // dp[i] = number of ways to reach stair i
        vector<int> dp(n + 1);

        // 0 stairs → 1 way
        // (do nothing)
        dp[0] = 1;

        // 1 stair → 1 way
        dp[1] = 1;

        // Calculate ways for every stair
        for(int i = 2; i <= n; i++) {

            // We can reach i from:
            // i-1 by taking 1 step
            // i-2 by taking 2 steps
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return number of ways to reach n
        return dp[n];
    }
};