class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>,greater<int>> qu;
        
        for(int i=0 ; i<nums.size() ; i++){

            if(qu.size() < k){
                qu.push(nums[i]);
            }
            else{
                if(nums[i] > qu.top()){
                    qu.pop();
                    qu.push(nums[i]);
                }
            }
        }

        return qu.top();
        
    }
};