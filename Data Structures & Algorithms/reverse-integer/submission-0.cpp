class Solution {
public:
    int reverse(int x) {
        const int MAX = INT_MAX;
        const int MIN = INT_MIN;

        int res = 0;
        while(x != 0){
            int digit = x % 10;
            x /= 10;
            // cases of overflow
            if(res > MAX/10 || res < MIN / 10)
                return 0;
            if(res == MAX/10 && digit > MAX%10)
                return 0;
            if(res == MIN/10 && digit < MIN%10)
                return 0;
            res = res * 10 + digit;
        }
        return res;
    }
};