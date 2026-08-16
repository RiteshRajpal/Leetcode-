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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        //Base Case: root is NULL

        if(!root) return ans;
        // push root to queue
        q.push(root);
        while(!q.empty()){ //loop until no nodes left
        vector<int> level;  //to store current level
        int size = q.size();
        for(int i=0; i<size; i++){  //loop for each node in current level
        TreeNode* temp = q.front();

        q.pop();
        level.push_back(temp->val); //store node value
        if(temp->left) q.push(temp->left); //push left child for next level
        if(temp->right) q.push(temp->right); //push right chile for next level
        }
        ans.push_back(level);
        }
        return ans;
    }
};