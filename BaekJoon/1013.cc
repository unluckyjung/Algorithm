#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  regex reg("(100+1+|01)+");
  int n;
  cin >> n;

  string str;
  while (n--) {
    cin >> str;

    if (regex_match(str, reg)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
