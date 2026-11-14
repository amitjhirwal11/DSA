class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        int n = nums.size();


        if(n%k != 0){
            return false;
        }

        map<int,int> mpp;

        for(auto it : nums){
            mpp[it]++;
        }

        while(!mpp.empty()){
            int ele = mpp.begin()->first;
            for(int i=0 ; i<k ; i++){
                if(mpp.find(ele+i) == mpp.end()){
                    return false;
                }

                mpp[ele+i]--;
                if(mpp[ele+i] == 0){
                    mpp.erase(ele+i);
                }

            }
        }

        return true;
        
    }
};