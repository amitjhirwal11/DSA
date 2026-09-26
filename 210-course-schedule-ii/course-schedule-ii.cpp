class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;

        vector<int> degree(n,0);
        vector<int> ans;

        vector<vector<int>> adj(n);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;;
        }

        queue<int> qu;
        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(degree[i] == 0){
                qu.push(i);
            }
        }

        //int count = 0;

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            ans.push_back(node);
            count++;
            for(auto it : adj[node]){
                degree[it]--;
                if(degree[it] == 0){
                    qu.push(it);
                }
            }
        }

        if(count == n){
            return ans;
        }

        return {};

    }
};