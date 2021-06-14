#include <bits/stdc++.h>

#define MAX 100002

void init();

void solve();

using namespace std;

int n, m;
int dp[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
//  freopen("input.txt", "r", stdin);

  init();
  solve();

  return 0;
}

void init() {

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num;
    dp[i] = dp[i - 1] + num;
  }
}

void solve() {
  while (m--) {
    int start, end;
    cin >> start >> end;
    cout << dp[end] - dp[start - 1] << "\n";
  }
}
