# Longest Common Prefix

## Cpp

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        int minSize = INT_MAX;
        
        for(string str: strs){
            minSize = min(minSize, (int)str.size());
        }
        
        string baseString = strs[0];
        
        for(int i = 0; i < minSize; ++i){
            if(!isAllSame(strs, baseString[i], i)) return answer;
            answer.push_back(baseString[i]);
        }
        return answer;
    }
    
    bool isAllSame(vector<string>& strs, char ch, int index){
        for(string str: strs){
            if(str[index] == ch) continue;
            return false;
        }
        return true;
    }
};
```