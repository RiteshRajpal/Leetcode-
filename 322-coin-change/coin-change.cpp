class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        // dp[i] = minimum number of coins needed
        // to make amount i
        vector<int> dp(amount + 1, amount + 1);

        // 0 coins are needed to make amount 0
        dp[0] = 0;

        // Calculate answer for every amount
        for(int i = 1; i <= amount; i++) {

            // Try every coin
            for(int coin : coins) {

                // We can use this coin only if
                // coin <= current amount
                if(coin <= i) {

                    // Take the minimum:
                    // current answer
                    // OR use this coin + answer for remaining amount
                    dp[i] = min(dp[i],
                                dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] was never updated,
        // amount cannot be formed
        if(dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};