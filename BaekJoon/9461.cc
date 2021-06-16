#include <bits/stdc++.h>

using namespace std;

const int MAX = 102;
long long dp[MAX] = {0, 1, 1, 1, 2};

void solve();

void init();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  init();
  solve();

  return 0;
}

void init() {
  for (int i = 5; i <= 100; ++i) {
    dp[i] = dp[i - 5] + dp[i - 1];
  }
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }
}
