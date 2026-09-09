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
    void leftside(TreeNode* root , stack<TreeNode*> &st){
        
        while(root != NULL){
            st.push(root);
            root = root->left;
        }

    }

    void righttside(TreeNode* root , stack<TreeNode*> &st){
        
        while(root != NULL){
            st.push(root);
            root = root->right;
        }
        
    }

    bool findTarget(TreeNode* root, int k) {

        stack<TreeNode*> left;
        stack<TreeNode*> right;

        leftside(root,left);
        righttside(root,right);

        while(!left.empty() && !right.empty() && left.top() != right.top()){

            TreeNode* lft = left.top();
            TreeNode* rht = right.top();

            int sum = lft->val+rht->val;

            if(sum == k){
                return true;
            }
            else if(sum < k){
                TreeNode* node = left.top();
                left.pop();
                leftside(node->right,left);
            }
            else{
                TreeNode* node = right.top();
                right.pop();
                righttside(node->left,right);
            }
        }

        return false;

        
    }
};