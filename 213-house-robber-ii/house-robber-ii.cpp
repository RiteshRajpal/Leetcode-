class Solution {
public:

    // Normal House Robber logic for a given range
    int robRange(vector<int>& nums, int start, int end) {

        // Maximum money from two houses back
        int prev2 = 0;

        // Maximum money from the previous house
        int prev1 = 0;

        // Process houses from start to end
        for (int i = start; i <= end; i++) {

            // Option 1: Rob the current house
            int take = nums[i] + prev2;

            // Option 2: Skip the current house
            int skip = prev1;

            // Choose the maximum money
            int curr = max(take, skip);

            // Update previous two results
            prev2 = prev1;
            prev1 = curr;
        }

        // Return maximum money for this range
        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // If there is only one house, rob it
        if (n == 1)
            return nums[0];

        // Case 1: Exclude the last house
        int case1 = robRange(nums, 0, n - 2);

        // Case 2: Exclude the first house
        int case2 = robRange(nums, 1, n - 1);

        // Return the maximum of both cases
        return max(case1, case2);
    }
};