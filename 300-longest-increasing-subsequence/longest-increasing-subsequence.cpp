class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = length of LIS ending at index i
        vector<int> dp(n, 1);

        // Store the overall maximum
        int ans = 1;

        // Check every element
        for(int i = 0; i < n; i++) {

            // Check all elements before i
            for(int j = 0; j < i; j++) {

                // If nums[j] can come before nums[i]
                if(nums[j] < nums[i]) {

                    // Add nums[i] to the subsequence
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            // Update overall answer
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};