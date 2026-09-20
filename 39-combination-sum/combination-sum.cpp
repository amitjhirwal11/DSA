class Solution {
public:

    void find(vector<int>& candidates , int ind , int target , vector<vector<int>> &ans , vector<int> ans2){

        int n = candidates.size();

        if(ind >= n){
            return ;
        }

        if(target == 0){
            ans.push_back(ans2);
            return ;
        }

        find(candidates,ind+1,target,ans,ans2);

        //int pick = 0;

        if(candidates[ind] <= target){

            ans2.push_back(candidates[ind]);
            find(candidates,ind,target-candidates[ind],ans,ans2);
            ans2.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ans2;

        find(candidates,0,target,ans,ans2);
        return ans;
        
    }
};