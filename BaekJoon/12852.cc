#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 2;
int dp[MAX] = {0, 0, 1, 1};
int pre[MAX] = {-1, -1, 1, 1};

void solve();

void printAnswer(int n);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  solve();

  return 0;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 4; i <= n; ++i) {
    dp[i] = dp[i - 1] + 1;
    pre[i] = i - 1;

    if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
      dp[i] = dp[i / 2] + 1;
      pre[i] = i / 2;
    }

    if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
      dp[i] = dp[i / 3] + 1;
      pre[i] = i / 3;
    }
  }
  printAnswer(n);
}

void printAnswer(int n) {
  cout << dp[n] << "\n";
  int cur = n;
  cout << cur << " ";
  while (pre[cur] != -1) {
    cout << pre[cur] << " ";
    cur = pre[cur];
  }
}