class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // If both p and q are smaller than root,
        // LCA must be in the left subtree
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both p and q are greater than root,
        // LCA must be in the right subtree
        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise, p and q are on different sides
        // OR root itself is p or q.
        // Therefore root is the LCA.
        return root;
    }
};