class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>> qu;
        

        for(int i=0 ; i<points.size() ; i++){

            int row = points[i][0];
            int col = points[i][1];

            int dist = row*row+col*col;

            

            if(qu.size() < k){
                qu.push({dist,{row,col}});
            }
            else if(qu.top().first > dist){
                qu.push({dist,{row,col}});
                qu.pop();
            }
            
        }
        vector<vector<int>> ans;

        while(!qu.empty()){
            auto p = qu.top();
            qu.pop();
            int row = p.second.first;
            int col = p.second.second;
            ans.push_back({row,col});
        }

        return ans;
    }
};