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

    vector<int> dfs(TreeNode* root , int &ans){
        //{bst,max,min,sum}
        if(root == NULL){
            return {1,INT_MIN,INT_MAX,0};
        }

        vector<int> left = dfs(root->left,ans);
        vector<int> right =  dfs(root->right,ans);

        if( left[0] && right[0] &&  left[1] < root->val && right[2] > root->val ){
            int sum = left[3]+right[3]+root->val;
            int mini = min(root->val,left[2]);
            int maxi = max(root->val,right[1]);

            ans = max(ans,sum);

            return {1,maxi,mini,sum};
        }

        return {0,INT_MAX,INT_MIN,0};

    }
    int maxSumBST(TreeNode* root) {

        int ans = 0;
        dfs(root,ans);
        return ans; 
    }
};