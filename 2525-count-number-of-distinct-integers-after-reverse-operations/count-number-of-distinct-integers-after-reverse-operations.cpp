class Solution {
public:

    int reverseNum(int n) {
        int ans = 0;

        while (n != 0) {
            int digit = n % 10;
            ans = ans * 10 + digit;
            n = n / 10;
        }

        return ans;
    }

    int countDistinctIntegers(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            st.insert(reverseNum(nums[i]));
        }

        return st.size();
    }
};