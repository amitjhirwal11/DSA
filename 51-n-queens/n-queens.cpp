class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++){
            path[i] = s;
        }
        recurse(ans,0,path,n);
        return ans;
    }

    void recurse(vector<vector<string>> &ans  , int col , vector<string> &path , int n){
        if(col == n){
            ans.push_back(path);
            return;
        }

        //string s = "";
        for(int i=0 ; i<n ; i++){
            if(ispossible( i,col,path,n)){
                path[i][col] = 'Q';
                recurse(ans ,col+1,path,n);
                path[i][col] = '.';
            }
        }
        //recurse(ans,row+1,col,path,n);
    }

    bool ispossible(  int row , int col , vector<string> &path,int n){
        int newr = row;
        int newc = col;
        //upper bound
        while(row >=0 && col>=0){
            if(path[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        row = newr;
        col = newc;
        while(col>=0){
            if(path[row][col] =='Q'){
                return false;
            }
            col--;
        }

        row = newr;
        col = newc;
        while(row<n && col>=0 ){
            if(path[row][col] =='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;

    }
};