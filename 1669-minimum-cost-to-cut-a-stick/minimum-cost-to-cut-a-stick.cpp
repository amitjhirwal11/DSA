class Solution {
public:

    int find(vector<int>& cuts , int i , int j,vector<vector<int>> &dp){

        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k=i ; k<=j ; k++){
            int cost = (cuts[j+1] - cuts[i-1])+find(cuts,k+1,j,dp)+find(cuts,i,k-1,dp);

            ans = min(ans,cost);
        }

        return dp[i][j] = ans;

    }
    int minCost(int n, vector<int>& cuts) {

        int t = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        vector<vector<int>> dp(t+2,vector<int>(t+2,-1));

        return find(cuts,1,t,dp);
        
    }
};