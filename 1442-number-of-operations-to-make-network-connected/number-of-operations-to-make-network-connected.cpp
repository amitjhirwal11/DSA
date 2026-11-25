class Solution {
public:


    vector<int>parent;
    vector<int> rank;

    int findp(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = findp(parent[n]);
    }

    void findbyr(int u , int v){
        int parent_u = findp(u);
        int parent_v = findp(v);

        if(parent_u == parent_v){
            return;
        }

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }
        else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {

        parent.resize(n);
        rank.resize(n);

        if(connections.size() < n-1){
            return -1;
        }

        int count = 0;

        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }

        

        for(int i=0 ; i<connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(findp(u) == findp(v)){
                count++;
            }
            else{
                findbyr(u,v);
            }

        }

        int extra = 0;
        for(int i=0 ; i<n ; i++){
            if(findp(i) == i){
                extra++;
            }
        }

        int ans = extra-1;
        if(ans <= count){
            return ans;
        }

        return -1;

       
        
        
    }
};