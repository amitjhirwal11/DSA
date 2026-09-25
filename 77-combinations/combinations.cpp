class Solution {
public:
    void finding(vector<vector<int>> &ans ,  vector<int> &ans2 , int n , int k , int ind){

        //unordered_set<vector<int>> mpp;

        if(ans2.size() == k ){
            ans.push_back(ans2);
            return ;
        }
        if(ind > n){
            return ;
        }
        
        ans2.push_back(ind);
        finding(ans,ans2,n,k,ind+1);
        ans2.pop_back();

        finding(ans,ans2,n,k,ind+1);

    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> ans2;
        finding(ans,ans2,n,k,1);

        

    

        return ans;
        
    }
};