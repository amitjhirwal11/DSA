class Solution {
public:

    int find(vector<vector<vector<int>>> &dp , vector<int>&prices , int k , int ind , int buy){

        int n = prices.size();
        if(ind >= n){
            return 0;
        }

        if(dp[ind][k][buy] != -1){
            return dp[ind][k][buy];
        }

        if(k <= 0){
            return 0;
        }

        int npick = find(dp,prices,k,ind+1,buy);
        int pick ;

        if(buy){
            pick = -prices[ind] + find(dp,prices,k,ind+1,buy-1);
        }
        else{
            pick = prices[ind] + find(dp,prices,k-1,ind+1,buy+1);
        }

        return dp[ind][k][buy] =  max(pick,npick);
    }
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return find(dp,prices,k,0,1);

        
    }
};