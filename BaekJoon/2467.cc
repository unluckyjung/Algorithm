#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int n;
int ans1, ans2;
int minDiff = INT_MAX;

void getMinDiff(int num1, int num2) {
  if (num1 == num2) return;
  if (abs(num1 + num2) < abs(minDiff)) {
    ans1 = num1;
    ans2 = num2;
    minDiff = ans1 + ans2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  for (int num1 : nums) {
    int num2;
    auto it = lower_bound(nums.begin(), nums.end(), -num1);

    if (it == nums.end()) {
      num2 = *nums.rbegin();
    } else {
      num2 = *it;
    }

    if (num2 != *nums.begin()) {
      getMinDiff(num1, *(it - 1));
    }

    getMinDiff(num1, num2);

    if (num2 != *nums.rbegin()) {
      getMinDiff(num1, *(it + 1));
    }
  }

  cout << min(ans1, ans2) << " " << max(ans1, ans2) << "\n";

  return 0;
}
