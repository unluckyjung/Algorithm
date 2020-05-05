class Solution {
public:
    int findComplement(int num) {
        int cnt = 0, ret = 0;
        
        while(num){
            if(num % 2 == 0) ret += pow(2, cnt);
            cnt++;  num /= 2;
        }
        return ret;
    }
};