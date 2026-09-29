class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        // Sort pairs based on their ending value
        sort(pairs.begin(), pairs.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });

        // Number of pairs selected
        int count = 0;

        // Ending value of the last selected pair
        int lastEnd = INT_MIN;

        // Check every pair
        for (auto& p : pairs) {

            // We can add this pair only if
            // its starting value is greater than
            // the ending value of the previous pair
            if (p[0] > lastEnd) {

                // Select this pair
                count++;

                // Update the ending value
                lastEnd = p[1];
            }
        }

        // Return maximum chain length
        return count;
    }
};