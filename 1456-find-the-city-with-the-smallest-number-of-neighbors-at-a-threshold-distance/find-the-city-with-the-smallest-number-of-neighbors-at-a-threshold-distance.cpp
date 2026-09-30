class Solution {
public:
    int counts(vector<vector<pair<int,int>>> &adj , int src , int &distanceThreshold  ){

        int n = adj.size();
        vector<int> dist(n,1e9);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> qu;

        dist[src] = 0;

        qu.push({0,src});

        while(!qu.empty()){
            auto p = qu.top();
            int d = p.first;
            int node = p.second;
            qu.pop();

            if(d > distanceThreshold) continue;

            for(auto it : adj[node]){
                int snode = it.first;
                int distance = it.second;


                if(dist[snode] > dist[node]+distance){

                    dist[snode] = dist[node]+distance;
                    qu.push({dist[snode],snode});

                }
            }
        }

        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(dist[i] <= distanceThreshold){
                count++;
            }
        }

        return count;


    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n);
        unordered_map<int,int> mpp;
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int city = -1;
        int numb = INT_MAX;

        for(int i=0 ; i<n ; i++){

            int k = counts(adj,i,distanceThreshold);
            if(k < numb){
                city = i;
                numb = k;
            }
            else if ( k  == numb){
                city = max(city,i);
            }
        }

        return city;



        
        


 
        
    }
};