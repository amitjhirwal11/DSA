class Solution {
public:

    bool checking(string &s , string &p , int ind1 , int ind2 , vector<vector<int>>&dp ){
        if(ind1 <0 && ind2 < 0){
            return true;
        }
        if(ind2 < 0){
            return false;
        }

        

        if(ind1 < 0 ){
            for(int i=0 ; i<=ind2 ; i++){
                if(p[i] != '*'){
                    return false;
                }

            }
            return true;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == p[ind2] || p[ind2] == '?'){
            return dp[ind1][ind2] = checking(s,p,ind1-1,ind2-1,dp);
        }

        if(p[ind2] =='*'){
            return dp[ind1][ind2] = checking(s,p,ind1-1,ind2,dp) || checking(s,p,ind1,ind2-1,dp);
        }

        return dp[ind1][ind2] = false;


    }

    
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return checking(s,p,n-1,m-1,dp);


        
    }
};