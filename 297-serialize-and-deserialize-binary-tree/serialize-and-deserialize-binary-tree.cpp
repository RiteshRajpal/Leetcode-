class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // If the node is NULL,
        // store "NULL" so we remember its position.
        if(!root)
            return "NULL,";

        // Store:
        // current value + left subtree + right subtree
        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        // Convert the string into a stringstream
        stringstream ss(data);

        // Rebuild the tree
        return decode(ss);
    }


    // Helper function to decode the tree
    TreeNode* decode(stringstream& ss) {

        string curr;

        // Read one value until comma
        getline(ss, curr, ',');

        // If the value is NULL,
        // there is no node here.
        if(curr == "NULL") {
            return NULL;
        }

        // Convert string value to integer
        // and create a new node.
        TreeNode* root = new TreeNode(stoi(curr));

        // Build the left subtree
        root->left = decode(ss);

        // Build the right subtree
        root->right = decode(ss);

        // Return the created node
        return root;
    }
};