# Remove Duplicates from Sorted Array

## 풀이1

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqCount = 0;
        int beforeIndex = 0;
        
        for(int i = 0 ; i < (int)nums.size(); ++i){
            int num = nums[i];

            if(i == 0){
                beforeIndex = i;
                uniqCount++;
                continue;
            }
            
            if (nums[i] == nums[beforeIndex]) continue;
            uniqCount++;
            nums[beforeIndex + 1] = nums[i];
            beforeIndex++;
        }
        return uniqCount;
    }
};
```

- 공간복잡도 O(2)로 푼 풀이 `(uniqueCount, beforeIndex)`

## 풀이2

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicateCount = 0;
        
        for(int i = 1; i < (int)nums.size(); ++i){
            if(nums[i] == nums[i-1]) duplicateCount++;
            else nums[i - duplicateCount] = nums[i];
        }
        return nums.size() - duplicateCount;
    }
};
```

- 모든 요구사항을 만족한 O(1) 풀이

## 다른 사람 풀이
- For Each문으로 풀어낸 [풀이](https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/discuss/11780/5-lines-C++Java-nicer-loops)도 있더라.