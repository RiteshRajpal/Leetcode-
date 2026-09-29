class Solution {
public:
    int uniquePaths(int m, int n) {

        // dp[i][j] = number of ways to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // First column:
        // There is only one way to reach these cells - move down
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // First row:
        // There is only one way to reach these cells - move right
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // Fill the remaining cells
        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                // We can reach current cell from:
                // 1. Top
                // 2. Left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Bottom-right cell contains the answer
        return dp[m - 1][n - 1];
    }
};