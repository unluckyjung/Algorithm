# 3Sum

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
      vector<vector<int>> answer;

      int n = nums.size();
      sort(nums.begin(), nums.end());

      for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) break;

        if (i > 0 and nums[i] == nums[i - 1]) continue;

        int two = i + 1;
        int three = n - 1;

        while (two < three) {
          int sum = nums[i] + nums[two] + nums[three];

          if (sum == 0) {
            answer.push_back({nums[i], nums[two], nums[three]});
            int beforeTwo = nums[two];
            int beforeThree = nums[three];

            while (two < three && nums[two] == beforeTwo) {
              two++;
            }
            while (two < three && nums[three] == beforeThree) {
              three--;
            }
          } else if (sum < 0) {
            two++;
          } else {
            three--;
          }
        }
      }
      return answer;
    }
};
```