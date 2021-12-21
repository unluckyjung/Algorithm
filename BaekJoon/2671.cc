#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  regex reg("(100+1+|01)+");

  string str;
  cin >> str;
  if (regex_match(str, reg)) cout << "SUBMARINE\n";
  else cout << "NOISE";

  return 0;
}
