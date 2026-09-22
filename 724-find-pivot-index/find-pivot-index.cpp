class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix1(n);
        prefix1[0] = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            prefix1[i] = prefix1[i-1]+nums[i];
        }

        vector<int> prefix2(n);
        prefix2[n-1] = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            prefix2[i] = prefix2[i+1]+nums[i];
        }

        for(int i=0 ; i<n ; i++){
            if(prefix1[i] == prefix2[i]){
                return i;
            }
        }
        return -1;
    }
};