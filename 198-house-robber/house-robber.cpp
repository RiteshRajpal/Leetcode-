class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        // If there are no houses, we can rob 0 money
        if (n == 0)
            return 0;

        // If there is only one house, rob it
        if (n == 1)
            return nums[0];

        // dp[i] stores the maximum money we can rob
        // from houses 0 to i
        vector<int> dp(n, 0);

        // Base case: Only one house
        dp[0] = nums[0];

        // Base case: Choose the richer of the first two houses
        dp[1] = max(nums[0], nums[1]);

        // Calculate the maximum money for each remaining house
        for (int i = 2; i < n; i++) {

            // Option 1: Skip the current house
            int skip = dp[i - 1];

            // Option 2: Rob the current house
            // Add its money to the best result from i - 2
            int take = nums[i] + dp[i - 2];

            // Store the maximum of robbing or skipping
            dp[i] = max(take, skip);
        }

        // Maximum money after considering all houses
        return dp[n - 1];
    }
};