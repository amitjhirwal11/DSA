class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<pair<int,int>> ad;
        for(int i=0 ; i<arr.size() ; i++){
            ad.push_back({abs(arr[i]-x),arr[i]});
        }
         
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
        priority_queue<pair<int,int>> qu2;

        for(int i=0 ; i<ad.size() ; i++){
            if(qu2.size() < k){
                qu2.push({ad[i].first,ad[i].second});
            }
            else{
                auto p = qu2.top();
                int diff = p.first;
                if(diff > ad[i].first){
                    qu2.push({ad[i].first,ad[i].second});
                    qu2.pop();
                }
            }
        }

        vector<int> ans;
        while(!qu2.empty()){
            auto p = qu2.top();
            qu2.pop();
            ans.push_back(p.second);
        }

        sort(ans.begin(),ans.end());
        return ans;
        
    }
};