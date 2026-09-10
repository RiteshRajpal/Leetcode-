class Solution {
public:

    // DFS function to change all connected
    // cells having the original color
    void dfs(vector<vector<int>>& image,
             int i, int j,
             int newcolor,
             int orgColor) {

        // Stop if:
        // 1. We go outside the image
        // 2. Current cell has a different color
        // 3. Current cell is already the new color
        if(i < 0 || j < 0 ||
           i >= image.size() ||
           j >= image[0].size() ||
           image[i][j] != orgColor ||
           image[i][j] == newcolor) {
            return;
        }

        // Change current cell to the new color
        image[i][j] = newcolor;

        // Go UP
        dfs(image, i-1, j, newcolor, orgColor);

        // Go RIGHT
        dfs(image, i, j+1, newcolor, orgColor);

        // Go DOWN
        dfs(image, i+1, j, newcolor, orgColor);

        // Go LEFT
        dfs(image, i, j-1, newcolor, orgColor);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc,
                                   int color) {

        // Store the original color of starting cell
        int orgColor = image[sr][sc];

        // If old and new colors are same,
        // nothing needs to be changed
        if(orgColor == color)
            return image;

        // Start DFS from starting cell
        dfs(image, sr, sc, color, orgColor);

        // Return modified image
        return image;
    }
};