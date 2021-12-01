# Single Number

## cpp 풀이

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        
        for(int num : nums){
            answer ^= num;
        }
        
        return answer;
    }
};
```