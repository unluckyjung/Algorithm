# Contains Duplicate

## Cpp

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> used;
        for(int num : nums){
            if(used[num]) return true;
            used[num] = true;
        }
        return false;
    }
};
```

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> uniqueNums {nums.begin(), nums.end()};
        return nums.size() != uniqueNums.size();
    }
};
```


## Java

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Boolean> used = new HashMap<>();
        for (int num : nums) {
            if (used.containsKey(num)) {
                return true;
            }
            used.put(num, true);
        }
        return false;
    }
}
```

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> uniqueNums = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        return uniqueNums.size() != nums.length;
    }
}
```

## Kotlin

```kotlin
class Solution {
    fun containsDuplicate(nums: IntArray): Boolean {
        val set = mutableSetOf<Int>()

        nums.forEach {
            if(set.contains(it)) return true
            set.add(it)
        }

        return false
    }
}
```