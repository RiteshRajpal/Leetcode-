class Solution {
public:

    // Counts how many nodes we have visited
    // during inorder traversal
    int prevOrder = 0;

    int kthSmallest(TreeNode* root, int k) {

        // If there is no node,
        // nothing can be found here
        if(root == NULL) {
            return -1;
        }

        // 1. First visit the left subtree
        if(root->left != NULL) {

            int leftAns = kthSmallest(root->left, k);

            // If the answer was found in the left subtree,
            // immediately return it
            if(leftAns != -1) {
                return leftAns;
            }
        }

        // 2. Visit the current node
        // If this is the k-th node,
        // return its value
        if(prevOrder + 1 == k) {
            return root->val;
        }

        // Increase the count after visiting this node
        prevOrder = prevOrder + 1;

        // 3. Finally visit the right subtree
        if(root->right != NULL) {

            int rightAns = kthSmallest(root->right, k);

            // If the answer was found in the right subtree,
            // return it
            if(rightAns != -1) {
                return rightAns;
            }
        }

        // Answer was not found in this subtree
        return -1;
    }
};