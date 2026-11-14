class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();


        if(n%groupSize != 0){
            return false;
        }

        map<int,int> mpp;

        for(auto it : hand){
            mpp[it]++;
        }

        while(!mpp.empty()){
            int ele = mpp.begin()->first;
            for(int i=0 ; i<groupSize ; i++){
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