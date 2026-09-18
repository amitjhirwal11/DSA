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

    TreeNode* find(vector<int>& preorder , int upprbound , int &curr){

        if(curr == preorder.size() || preorder[curr] > upprbound ){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[curr]);
        curr++;

        root->left = find(preorder,root->val,curr);
        root->right = find(preorder,upprbound,curr);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int curr = 0;
        return find(preorder,INT_MAX,curr);
        
    }
};