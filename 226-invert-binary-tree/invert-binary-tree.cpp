/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // If the tree is empty, return NULL
        if(root == NULL)
            return NULL;

        // Invert the left subtree
        invertTree(root->left);

        // Invert the right subtree
        invertTree(root->right);

        // Store the left child temporarily
        TreeNode* temp = root->left;

        // Put the right child on the left
        root->left = root->right;

        // Put the original left child on the right
        root->right = temp;

        // Return the root of the inverted tree
        return root;
    }
};