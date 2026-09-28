class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> qu;
        qu.push({src,{0,0}});

        dist[src] = 0;

        while(!qu.empty()){
            auto p = qu.front();
            qu.pop();

            int node = p.first;
            int distance = p.second.second;
            int stops = p.second.first;

            if(stops > k){
                continue;
            }

            for(auto it : adj[node]){
                int snode = it.first;
                int dsti = it.second;

                if(dist[snode] > distance+dsti && stops <= k){
                    dist[snode] = distance+dsti;
                    qu.push({snode,{stops+1,dist[snode]}});
                }
            }


        }

        if(dist[dst] == 1e9){
            return -1;
        }

        return dist[dst];

        
    }
};