class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;       // Stores number -> its index

        for(int i = 0; i < nums.size(); i++) {  // Traverse the array

            int need = target - nums[i];  // Number needed to make target

            if(mp.count(need))            // Check if needed number was seen
                return {mp[need], i};     // Return its index and current index

            mp[nums[i]] = i;              // Store current number and index
        }

        return {};                        // No pair found
    }
};