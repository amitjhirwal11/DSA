/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mpp;
        queue<TreeNode*>qu;
        mpp[root] = NULL;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* p = qu.front();
            qu.pop();
            if( p->left != NULL){
                mpp[p->left] = p;
                qu.push(p->left);
            }
            if(p->right != NULL){
                mpp[p->right] = p;
                qu.push(p->right);
            }
        }

        //bfs from target

        vector<int> ans;
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        qu.push(target);
        int distance = 0;
        while(!qu.empty()){

            int size = qu.size();

            if(distance == k){
                while(!qu.empty()){
                    ans.push_back(qu.front()->val);
                    qu.pop();
                }
                return ans;
            }

            for(int i=0 ; i<size ; i++){
                TreeNode* node = qu.front();
                qu.pop();

                if(node->left != NULL && !visited.count(node->left)){
                    qu.push(node->left);
                    visited.insert(node->left);
                    
                }
                if(node->right != NULL && !visited.count(node->right)){
                    qu.push(node->right);
                    visited.insert(node->right);
                    
                }
                if(mpp[node] != NULL && !visited.count(mpp[node])){
                    qu.push(mpp[node]);
                    visited.insert(mpp[node]);
                    
                }
            }

            distance++;
        }

        return ans;
    }
};