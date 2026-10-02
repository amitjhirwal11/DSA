class Solution {
public:

    int find(vector<int> & nums  , int ind , int target , vector<vector<int>> &dp){
        
        if(target == 0){
            return true;
        }
        if(ind == 0){
            return (nums[0] == target);
        }
        
        if(ind < 0 ){
            return false;
        }
        
        
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        
        int npick = find(nums,ind-1,target,dp);
        int pick = 0;
        if(target >= nums[ind]){
            pick = find(nums,ind-1,target-nums[ind],dp);
        }
        
        return dp[ind][target] =  (pick || npick);
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int k = 0;
        for(int i=0 ; i<n ; i++){
            k += nums[i];
        }
        if(k%2  == 1){
            return false;
        }
        k = k/2;

        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return find(nums,n-1,k,dp);
        
    }
};