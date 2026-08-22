class Solution {
public:

    // Helper function
    // minNode = minimum allowed boundary
    // maxNode = maximum allowed boundary
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {

        // Empty tree is a valid BST
        if(root == NULL) {
            return true;
        }

        // Current value must be greater than min boundary
        if(minNode != NULL && root->val <= minNode->val) {
            return false;
        }

        // Current value must be smaller than max boundary
        if(maxNode != NULL && root->val >= maxNode->val) {
            return false;
        }

        // Left subtree:
        // value must be between minNode and root
        //
        // Right subtree:
        // value must be between root and maxNode
        return helper(root->left, minNode, root) &&
               helper(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {

        // Initially there is no minimum or maximum boundary
        return helper(root, NULL, NULL);
    }
};