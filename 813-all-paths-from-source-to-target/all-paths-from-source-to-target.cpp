class Solution {
public:

    void dfs(vector<vector<int>>& graph , vector<int> &vis , int node , vector<vector<int>> &ans , vector<int> ans2 ){

        int n = graph.size();
        if(node == n-1){
            ans.push_back(ans2);
            return ;
        }
        
        
        for(auto it : graph[node]){
            if(!vis[it]){
                ans2.push_back(it);
                dfs(graph,vis,it,ans,ans2);
                
                ans2.pop_back();
            }

        }
        


    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> ans;
        vector<int> ans2;
        ans2.push_back(0);

        vector<int> vis(n,0);
        dfs(graph,vis,0,ans,ans2);

        return ans;

        
    }
};