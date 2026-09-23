class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        int st = 0;
        int end = n-1;

        if(nums.size() == 1){
            return nums[0];
        }

        while(st<=end){

            int mid = (st+end)/2;

            if(mid == 0 || mid == n-1){
                return nums[mid];
            }

            if(nums[mid] == nums[mid-1] ){

                if(mid%2 == 0){

                    end = mid-1;

                }
                else{
                    st = mid+1;
                }
            }
            else if(nums[mid] == nums[mid+1] ){
                if(mid%2 == 0){
                    st = mid+1;
                }
                else{
                    end = mid-1;

                }
            }
            else{
                return nums[mid];
                break;
            }
        }

        return -1;
        
    }
};