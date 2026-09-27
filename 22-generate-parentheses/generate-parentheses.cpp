class Solution {
public:

    void find(string s , vector<string> &ans , int open , int close  , int n ){
        
        if (s.size() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            find(s,ans,open+1,close,n);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            find(s,ans,open,close+1,n);
            s.pop_back();
        }


        
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
       
        find("",ans,0,0,n);

        return ans;
        
    }
};