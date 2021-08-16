#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
  int answer = 0;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  for (int i = n - 1; i > 0; --i) {
    int cur = nums[i];
    if (nums[i - 1] >= cur) {
      int diff = nums[i - 1] - cur + 1;
      nums[i - 1] -= diff;
      answer += diff;
    }
  }
  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  solve();

  return 0;
}
