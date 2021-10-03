class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        
        while(x != 0){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        if(ret < INT_MIN || ret > INT_MAX) return 0;
        return (int)ret;
    }
};