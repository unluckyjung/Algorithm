
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> sCount, tCount;
        for(char c : s){
            sCount[c]++;
        }
        for(char c : t){
            tCount[c]++;
        }
        return sCount == tCount;
    }
};
```

- string을 소팅한뒤에 같은지 판별해서 풀이한방법도 있었다.
- https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/discuss/66519/2-C++-Solutions-with-Explanations