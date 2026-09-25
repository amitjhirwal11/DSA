class Solution {
public:

    int find(vector<int>& nums , int ind , int prev , vector<vector<int>> &dp ){

        

        if(ind < 0 ){
            return 0;
        }

        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }

        

        int npick = find(nums,ind-1,prev,dp);
        int pick = 0;
        if(prev == -1 || nums[ind] < nums[prev]){
            pick = 1+find(nums,ind-1,ind,dp);
        }

        return dp[ind][prev+1] = max(pick,npick);


    }
    int lengthOfLIS(vector<int>& nums) {



        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return find(nums,n-1,-1,dp);


    }
};