#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  multiset<int> s;

  while (n--) {
    char cmd;
    int num;
    cin >> cmd >> num;

    if (cmd == 'I') {
      s.insert(num);
    } else {
      if (s.empty()) continue;

      if (num == -1) {
        s.erase(s.begin());
      } else {
        int maxValue = *s.rbegin();
        s.erase(s.find(maxValue));
      }
    }
  }

  if (s.empty()) cout << "EMPTY\n";
  else cout << *s.rbegin() << " " << *s.begin() << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  int t;

  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
