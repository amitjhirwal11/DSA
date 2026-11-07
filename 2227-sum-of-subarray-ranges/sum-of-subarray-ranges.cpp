class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        long long ans = 0;
        int n = nums.size();

        for(int i=0 ; i<nums.size() ; i++){
            int largest = nums[i];
            int mini = nums[i];
            for(int j=i ; j<nums.size() ; j++){
                largest = max(largest,nums[j]);
                mini = min(mini,nums[j]);
                ans += (largest-mini);
            }
        }

        return ans;
        
    }
};