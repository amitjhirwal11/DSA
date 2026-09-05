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
    TreeNode* building(vector<int>& inorder , vector<int>& postorder , int &preindex , int start , int end){
        if(start > end){
            return NULL;
        }

        int rootv = postorder[preindex--];
        TreeNode* root = new TreeNode(rootv);

        int findind = start;
        while(inorder[findind] != rootv){ 
            findind++;
        }

        
        root->right = building(inorder,postorder , preindex , findind+1 , end);
        root->left = building(inorder,postorder, preindex , start , findind-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int preindex = n-1;
        return building(inorder,postorder,preindex,0,n-1);
    }
};