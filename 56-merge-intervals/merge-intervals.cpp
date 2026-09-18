class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;

        int str = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1 ; i<intervals.size() ; i++){

            if(intervals[i][0] <= end){
                str = min(intervals[i][0],str);
                end = max(intervals[i][1],end);
            }
            else{
                ans.push_back({str,end});
                str = intervals[i][0];
                end = intervals[i][1];
            }

            //ans.push_back({str,end});

        }

        ans.push_back({str,end});

        return ans;
        
    }
};