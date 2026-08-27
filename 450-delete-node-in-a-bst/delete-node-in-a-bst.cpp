class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {

        // If tree is empty, nothing to delete
        if(root == NULL)
            return NULL;

        // If key is smaller, go to left subtree
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // If key is greater, go to right subtree
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // We found the node
        else {

            // Case 1:
            // No left child
            if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2:
            // No right child
            if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3:
            // Node has two children

            // Find the smallest node in the right subtree
            TreeNode* temp = root->right;

            while(temp->left != NULL) {
                temp = temp->left;
            }

            // Copy successor's value into current node
            root->val = temp->val;

            // Delete the duplicate successor node
            root->right = deleteNode(root->right, temp->val);
        }

        // Return the root
        return root;
    }
};