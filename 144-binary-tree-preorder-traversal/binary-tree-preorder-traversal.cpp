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
    vector<int> preorderTraversal(TreeNode* root) {
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
                    inorder.push_back(curr->val);

                    // Go to left subtree
                    curr = curr->left;
                }

                else {
                    // Remove thread
                    prev->right = NULL;

                    // Visit curr
                    

                    // Go to right subtree
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};