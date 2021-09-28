#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t, n;
ll dayPrice[1000000 + 2];
ll afterMaxPrice[1000000 + 2];

void solve() {

  ll benefit = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> dayPrice[i];
  }

  ll maxPrice = 0;
  for (int i = n; i > 0; --i) {
    maxPrice = max(maxPrice, dayPrice[i]);
    afterMaxPrice[i] = maxPrice;
  }

  for (int i = 1; i <= n; ++i) {
    if (dayPrice[i] < afterMaxPrice[i]) {
      benefit += afterMaxPrice[i] - dayPrice[i];
    }
  }
  cout << benefit << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  cin >> t;

  while (t--) {
    memset(dayPrice, 0, sizeof(dayPrice));
    memset(afterMaxPrice, 0, sizeof(afterMaxPrice));
    cin >> n;
    solve();
  }

  return 0;
}
