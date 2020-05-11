class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        bool trust_anyone[10002] = {false,};
        int trust_num[10002] = {0,};
        
        for(auto human: trust){
            trust_anyone[human[0]] = true;
            trust_num[human[1]]++;
        }
        
        for(int i = 1 ; i <= N; ++i){
            if(trust_anyone[i] == false and trust_num[i] == N-1) return i;
        }
        return -1;
    }
};