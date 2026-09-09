class Solution {
public:
    int reverse(int x) {

        int sign = 1;
        if(x<0){
            sign = -1;
        }

        if(x % 10 == 0){
            x = x/10;
        }

        int ans = 0;

        while( x != 0){
            int digit = x%10;


            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7) ){
                return 0;
            }

            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < -8)){
                return 0;
            }
            ans = ans*10 + digit;
            x = x/10;
        }

        return ans;
        
    }
};