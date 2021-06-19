#include <bits/stdc++.h>

using namespace std;

void solve();

bool isBigger(const string &answer, const char &num);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  solve();

  return 0;
}

void solve() {
  int n, k;
  cin >> n >> k;

  string number;
  cin >> number;

  string answer;
  for (char num : number) {
    while (k > 0 && !answer.empty() && isBigger(answer, num)) {
      answer.pop_back();
      k--;
    }
    answer.push_back(num);
  }

  while (k > 0) {
    answer.pop_back();
    k--;
  }

  cout << answer;
}

bool isBigger(const string &answer, const char &num) {
  return answer.back() < num;
}
