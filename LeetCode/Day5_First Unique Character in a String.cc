class Solution {
public:
    
    int firstUniqChar(string s) {
        int repeat[27] = {0, };
        
        for(char ch : s){
            repeat[ch-'a']++;
        }
        
        int len = s.size();
        for(int i = 0 ; i < len; ++i){
            if(repeat[s[i] - 'a'] == 1) return i;
        }
        return -1;
        
    }
};