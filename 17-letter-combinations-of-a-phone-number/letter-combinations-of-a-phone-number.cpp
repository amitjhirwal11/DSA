class Solution {
public:

    void find(unordered_map<int,string> &mpp , int ind , string t , vector<string> &ans , string digits){

        if(ind >= digits.size()){
            ans.push_back(t);
            return ;
        }

        int number = digits[ind] -'0';
        string s = mpp[number];

        for(int i=0 ; i<s.size() ; i++){
            t.push_back(s[i]);
            find(mpp,ind+1,t,ans,digits);
            t.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int,string> mpp;

         mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        vector<string> ans;

        if (digits.empty()) return {};
        string t;
        find(mpp,0,t,ans,digits);

        return ans;


    }
};