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

    TreeNode* building(vector<int>& preorder , vector<int>& inorder , int start , int end , int &preindex ){
        if(start>end){
            return NULL;
        }

        int rootv = preorder[preindex++];
        TreeNode* root = new TreeNode(rootv);

        int findino = start;
        while(inorder[findino] != rootv){
            findino++;
        }

        root->left = building(preorder,inorder,start,findino-1,preindex);
        root->right = building(preorder,inorder,findino+1,end,preindex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
        int n = inorder.size();
        return building(preorder,inorder,0,n-1,preindex);
    }
};