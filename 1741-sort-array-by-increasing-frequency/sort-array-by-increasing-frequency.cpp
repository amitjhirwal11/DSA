class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i=0  ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
        for(auto it : mpp){

            
            qu.push({it.second,-it.first});
        }

        vector<int> ans;

        while(!qu.empty()){
            auto p = qu.top();
            qu.pop();
            int freq = p.first;
            int node = -p.second;
            while(freq){
                ans.push_back(node);
                freq--;
            }
        }

        return ans;

    }
};