class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left == NULL) {
                // No left subtree
                inorder.push_back(curr->val);
                curr = curr->right;
            }

            else {
                // Find inorder predecessor
                TreeNode* prev = curr->left;

                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Create thread
                    prev->right = curr;

                    // Go to left subtree
                    curr = curr->left;
                }

                else {
                    // Remove thread
                    prev->right = NULL;

                    // Visit curr
                    inorder.push_back(curr->val);

                    // Go to right subtree
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};