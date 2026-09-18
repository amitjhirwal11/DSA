class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
    });
    int n = intervals.size();
    int str = intervals[0][0];
    int end = intervals[0][1];

    vector<vector<int>> ans;

    for(int i=1 ; i<n ; i++){
        if(intervals[i][0] > end){
            ans.push_back({str,end});
            str = intervals[i][0];
            end = intervals[i][1];
        }
        else{
            str = min(intervals[i][0],str);
            end = max(intervals[i][1],end);
        }
    }

    ans.push_back({str,end});

    return ans;



    }
};