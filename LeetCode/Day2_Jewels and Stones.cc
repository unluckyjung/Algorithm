#if 0
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int sum = 0;
        
        for(char my_stone : J){
            
            sum += count(S.begin(), S.end(), my_stone);
        }
        
        return sum;
    }
};

#else

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        unordered_set<char>s {J.begin(), J.end()};
        const auto no_exist = s.end();
        
        int cnt = 0;
        for(const char &jewel : S){
            if(s.find(jewel) != no_exist) cnt++;
        }
        
        return cnt;
    }
};

#endif