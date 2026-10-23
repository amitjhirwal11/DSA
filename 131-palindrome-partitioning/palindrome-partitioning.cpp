class Solution {
public:

    void find(vector<vector<string>> &ans , string s, int ind, vector<string> &ans2 ){

        int n =s.size();


        if(ind >= n){
            ans.push_back(ans2);
            return;
        }

        for(int i=ind ; i<s.size() ; i++){

            string t = s.substr(ind,i-ind+1);

            string p = t;
            reverse(p.begin(),p.end());
            if(t == p){
                ans2.push_back(t);
                find(ans,s,i+1,ans2);
                ans2.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {

        int n = s.size();
        
        vector<string> ans2;
        vector<vector<string>> ans;

        find(ans,s,0,ans2);

        return ans;
    }
};