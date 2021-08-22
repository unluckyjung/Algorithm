#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  cin >> n;
  vector<int> nums;
  vector<int> uniqueNums;

  while (n--) {
    cin >> m;
    nums.push_back(m);
    uniqueNums.push_back(m);
  }

  sort(uniqueNums.begin(), uniqueNums.end());
  uniqueNums.erase(unique(uniqueNums.begin(), uniqueNums.end()), uniqueNums.end());

  for (const int &num : nums) {
    cout << lower_bound(uniqueNums.begin(), uniqueNums.end(), num) - uniqueNums.begin() << " ";
  }

  return 0;
}
