class Solution {
public:

    int find(vector<int>& nums , int ind , vector<int> &dp){
        if(ind <0 ){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int st1 = find(nums,ind-2,dp)+nums[ind];
        int stp2 = find(nums,ind-1,dp);

        dp[ind] =  max(st1,stp2);
        return dp[ind];

    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);
        return find(nums,n-1,dp);
        
    }
};