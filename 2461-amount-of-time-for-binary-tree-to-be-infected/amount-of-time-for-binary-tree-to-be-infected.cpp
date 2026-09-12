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

    TreeNode* letsf(TreeNode* root, int start) {
    if (root == NULL)
        return NULL;

    if (root->val == start)
        return root;

    TreeNode* left = letsf(root->left, start);

    if (left != NULL)
        return left;

    return letsf(root->right, start);
    }


    int amountOfTime(TreeNode* root, int start) {

        if(root == NULL){
            return NULL;
        }
        

        TreeNode* temp = root;
        unordered_map<TreeNode*,TreeNode*> mpp;
        queue<TreeNode*> qu;
        qu.push(root);
        mpp[root] = NULL;

        while(!qu.empty()){

            TreeNode* node = qu.front();
            qu.pop();

            if(node->left){
                qu.push(node->left);
                mpp[node->left] = node;
            }
            if(node->right){
                qu.push(node->right);
                mpp[node->right] = node;
            }

        }

        TreeNode* find = letsf(root,start);

        queue<pair<TreeNode*,int>> qu2;
        qu2.push({find,0});

        unordered_set<TreeNode*> visited;
        visited.insert(find);
        int time = 0;

        while(!qu2.empty()){
            auto p = qu2.front();
            int t = p.second;
            TreeNode* node2 = p.first;
            qu2.pop();

            time = max(time,t);

            if(node2->left != NULL && !visited.count(node2->left)){
                qu2.push({node2->left,t+1});
                visited.insert(node2->left);
            }
            if(node2->right != NULL && !visited.count(node2->right)){
                qu2.push({node2->right,t+1});
                visited.insert(node2->right);
            }
            if(mpp[node2] != NULL && !visited.count(mpp[node2])){
                qu2.push({mpp[node2],t+1});
                visited.insert(mpp[node2]);
            }

        }

        return time;


    }
};