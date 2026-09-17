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

    int  succ(TreeNode* root ){

        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    


    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* temp2 = root;

        if(root == NULL){
            return NULL;
        }

        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        
        else{

        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }

        TreeNode* temp = root;
        int find = succ(root->right);
        //int k = find->val;
        root->val = find;
        root->right = deleteNode(root->right,find);

        }

        return root;


        
    }
};