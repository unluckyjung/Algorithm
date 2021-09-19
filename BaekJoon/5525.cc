#include <bits/stdc++.h>

using namespace std;

int wantIOICount, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  cin >> wantIOICount;
  cin >> m;

  string inputString;
  cin >> inputString;

  int answer = 0;

  int IOIChainCount = 0;
  for (int i = 1; i < m - 1;) {
    if (inputString[i - 1] == 'I' && inputString[i] == 'O' && inputString[i + 1] == 'I') {
      IOIChainCount++;
      i += 2;
      if (IOIChainCount == wantIOICount) {
        answer++;
        IOIChainCount--;
      }
    } else {
      IOIChainCount = 0;
      i++;
    }
  }

  cout << answer << "\n";

  return 0;
}
