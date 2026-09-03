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
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode* , TreeNode*> mpp;
        mpp[root] = NULL;
        queue<TreeNode*> qu2;
        qu2.push(root);
        TreeNode* target = NULL;
        while(!qu2.empty()){
            TreeNode* node = qu2.front();
            qu2.pop();

            if(node->val == start){
                target = node;
            }

            if(node->left){
                mpp[node->left] = node;
                qu2.push(node->left);
            } 
            if(node->right){
                mpp[node->right] = node;
                qu2.push(node->right);
            }

        }


        queue<pair<TreeNode*,int>> qu;
        qu.push({target,0});
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int t = 0;
        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();

            TreeNode* next = it.first;
            int time = it.second;

            t = max(time,t);

            if(next->left != NULL && !visited.count(next->left)){
                qu.push({next->left,time+1});
                visited.insert(next->left);
            }

            if(next->right != NULL && !visited.count(next->right)){
                visited.insert(next->right);
                qu.push({next->right,time+1});
            }

            if(mpp[next] != NULL && !visited.count(mpp[next])){
                qu.push({mpp[next],time+1});
                visited.insert(mpp[next]);
            }
        }

        return t;

    }
};