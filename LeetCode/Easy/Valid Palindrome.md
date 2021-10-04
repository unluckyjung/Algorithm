```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string onlyString;
        for(char ch : s){
            if(!isalnum(ch)) continue;
            onlyString.push_back(tolower(ch));
        }
        int onlyStringSize = onlyString.size();
        
        for(int i = 0; i < onlyStringSize; ++i){
            if(onlyString[i] != onlyString[onlyStringSize-1-i]) return false;
        }
        return true;
    }
};
```

- 이전에는 `isalpha && isdigit` 을 이용했는데, `isalnum` 이라는 메소드가 있는걸 알게 되었다.
