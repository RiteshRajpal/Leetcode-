class Solution {
public:
    bool canJump(vector<int>& nums) {

        // Farthest index we can currently reach
        int maxReach = 0;

        // Check every index
        for (int i = 0; i < nums.size(); i++) {

            // If current index is beyond our maximum reach,
            // we cannot even reach this index
            if (i > maxReach) {
                return false;
            }

            // Update the farthest position we can reach
            maxReach = max(maxReach, i + nums[i]);

            // If we can already reach the last index,
            // return true
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};