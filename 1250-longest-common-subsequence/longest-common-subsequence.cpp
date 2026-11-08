class Solution {
public:

    int find(string text1 , string text2 , int ind1 , int ind2 ){

        if(ind1 < 0){
            return 0;
        }
        if(ind2 < 0){
            return 0;
        }

        if(text1[ind1] == text2[ind2]){
            return 1+find(text1,text2,ind1-1,ind2-1);
        }
        else{
            return max(find(text1,text2,ind1-1,ind2),find(text1,text2,ind1,ind2-1));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        //return find(text1,text2,n-1,m-1);

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1 ; i<=n  ; i++){
            for(int j=1 ; j<=m ; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

        
    }
};