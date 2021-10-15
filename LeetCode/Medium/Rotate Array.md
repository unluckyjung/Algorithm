# Rotate Array

## Cpp1
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + cnt);
        reverse(nums.begin() + cnt, nums.end());
    }
};
```

- 공간복잡도 O(1) 처리를 어떻게 해야할지 고민을 많이했다.
- 뒤집는다는 발상을 처음에 하지 못했다.
  - swap하면서 위치를 바꿔가야하나?
  - 지점별로 이동할 위치를 덮어씌우면서 이동해야하나?

## Cpp2

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = k % nums.size();
        ::rotate(nums.rbegin(), nums.rbegin() + cnt, nums.rend());
    }
};
```

- rotate 메소드 한방으로도 처리가 가능하다.
- https://unluckyjung.github.io/cpp/2020/04/10/Rotate/