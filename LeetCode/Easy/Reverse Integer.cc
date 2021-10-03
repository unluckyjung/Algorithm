class Solution {
public:
    int reverse(int x) {
        string numStr;
        long long ret;
        if(x < 0){
            numStr = to_string(x).substr(1);
            ::reverse(numStr.begin(), numStr.end());
            ret = -(stoll(numStr));
        } else {
            numStr = to_string(x);
            ::reverse(numStr.begin(), numStr.end());
            ret = stoll(numStr);
        }
        if(ret < INT_MIN || ret > INT_MAX) return 0;
        return (int)ret;
    }
};