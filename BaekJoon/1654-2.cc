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
  ll answer = 0;

  while (start <= end) {
    ll lineLength = start + (end - start) / 2;
    if (isMatchLineNum(lineLength)) {
      answer = max(answer, lineLength);
      start = lineLength + 1;
    } else {
      end = lineLength - 1;
    }
  }
  return answer;
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
