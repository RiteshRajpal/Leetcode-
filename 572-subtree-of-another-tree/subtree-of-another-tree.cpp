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

    // Function to check whether two trees are identical
    bool isIdentical(TreeNode* p, TreeNode* q) {

        // If either node is NULL,
        // both must be NULL to be identical.
        if(p == NULL || q == NULL) {
            return p == q;
        }

        // Check:
        // 1. Current node values are equal
        // 2. Left subtrees are identical
        // 3. Right subtrees are identical
        return p->val == q->val
            && isIdentical(p->left, q->left)
            && isIdentical(p->right, q->right);
    }


    // Function to check whether subRoot
    // exists as a subtree inside root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If either tree is NULL,
        // they are a subtree only when both are NULL.
        if(root == NULL || subRoot == NULL) {
            return root == subRoot;
        }

        // If current root values are equal,
        // check whether the complete trees are identical.
        if(root->val == subRoot->val &&
           isIdentical(root, subRoot)) {

            return true;
        }

        // Search for subRoot in the left or right subtree.
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};