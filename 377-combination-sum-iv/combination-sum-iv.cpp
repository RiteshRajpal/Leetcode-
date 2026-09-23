class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        // dp[i] stores the number of ordered combinations
        // that add up to sum i
        vector<unsigned int> dp(target + 1, 0);

        // Base case: One way to make sum 0 (choose nothing)
        dp[0] = 1;

        // Try to build every sum from 1 to target
        for (int sum = 1; sum <= target; sum++) {

            // Try every number in nums as the last number
            for (int num : nums) {

                // We can use this number only if it
                // does not exceed the current sum
                if (num <= sum) {

                    // Add the number of ways to make
                    // the remaining sum
                    dp[sum] += dp[sum - num];
                }
            }
        }

        // Return the number of ways to make target
        return dp[target];
    }
};