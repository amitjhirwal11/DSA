class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> ans;

        int n = rowIndex;
        int k = 34;

        for(int i=0 ; i<k ; i++){

            vector<int> row(i+1,1);

            for(int j=1 ; j<i ; j++){

                row[j] = ans[i-1][j-1]+ans[i-1][j];

            }

            ans.push_back(row);

        }

        return ans[n];
        
    }
};