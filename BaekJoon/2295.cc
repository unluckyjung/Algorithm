#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
vector<int> twoSum;

int solve() {

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < n; ++ii) {
      twoSum.push_back(nums[i] + nums[ii]);
    }
  }

  sort(twoSum.begin(), twoSum.end());

  for (int totalSumIndex = n - 1; totalSumIndex > 0; --totalSumIndex) {
    for (int thirdNumIndex = 0; thirdNumIndex < totalSumIndex; ++thirdNumIndex) {
      int diff = nums[totalSumIndex] - nums[thirdNumIndex];
      if (binary_search(twoSum.begin(), twoSum.end(), diff)) {
        return nums[totalSumIndex];
      }
    }
  }
  return -1;
}

void input() {
  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  cout << solve() << "\n";

  return 0;
}
