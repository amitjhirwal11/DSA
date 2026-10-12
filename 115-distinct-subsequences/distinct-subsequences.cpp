class Solution {
public:

    int find(string s , string t , int ind1 , int ind2 , vector<vector<int>> &dp){

        if(ind2 < 0){
            return 1;
        }
        if(ind1 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] =   find(s,t,ind1-1,ind2-1,dp)+find(s,t,ind1-1,ind2,dp);
        }

        return dp[ind1][ind2] =  find(s,t,ind1-1,ind2,dp);

    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return find(s,t,n,m,dp);
    }


};