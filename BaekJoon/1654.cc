#include <bits/stdc++.h>

#define ll long long

using namespace std;

int haveLineNum;
int needLineNum;

vector<int> haveLines;

bool isMatchLineNum(ll lineLength) {
  int lineNum = 0;
  for (const int &line : haveLines) {
    lineNum += line / lineLength;
  }

  return lineNum >= needLineNum;
}

ll solve() {
  ll start = 1;
  ll end = INT_MAX;

  while (start < end) {
    ll lineLength = (start + end + 1) / 2;
    if (isMatchLineNum(lineLength)) {
      start = lineLength;
    } else {
      end = lineLength - 1;
    }
  }
  return start;
}

void input() {
  cin >> haveLineNum >> needLineNum;
  while (haveLineNum--) {
    int line;
    cin >> line;
    haveLines.push_back(line);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  input();
  cout << solve();

  return 0;
}
