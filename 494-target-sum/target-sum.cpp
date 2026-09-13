class Solution {
public:

    int find(vector<int>& nums , int k , int ind , vector<vector<int>> &dp){
        if(ind < 0){
            return k == 0 ? 1 : 0;
        }

        if(dp[ind][k] != -1){
            return dp[ind][k];
        }

        int npick = find(nums,k,ind-1,dp);
        int pick = 0;
        if(nums[ind] <= k){
            pick = find(nums,k-nums[ind],ind-1,dp);
        }

        return dp[ind][k] =  pick+npick;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
        }

        if (abs(target) > sum)
        return 0;

        //vector<vector<int>> dp(n,vector<int>(k,-1));
        if((target+sum)%2 == 1){
            return 0;
        }

        int k = (target+sum)/2;
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        //int n = nums.size();

        return find(nums,k,n-1,dp);

    }
};