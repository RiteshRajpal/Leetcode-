class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        // Store dictionary words in a set for fast searching
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        // dp[i] = true if first i characters can be formed
        vector<bool> dp(n + 1, false);

        // Empty string can always be formed
        dp[0] = true;

        // Check every prefix of the string
        for(int i = 1; i <= n; i++) {

            // Try every possible previous position
            for(int j = 0; j < i; j++) {

                // Previous part must be breakable
                if(dp[j] == true) {

                    // Get the substring from j to i-1
                    string word = s.substr(j, i - j);

                    // Check if this substring exists in dictionary
                    if(st.find(word) != st.end()) {

                        // First i characters can be formed
                        dp[i] = true;

                        // No need to check more positions
                        break;
                    }
                }
            }
        }

        // Return whether the entire string can be formed
        return dp[n];
    }
};