#include <bits/stdc++.h>

using namespace std;

void solve();

bool cmp(const string &num1, const string &num2);

string getMaxNum(const vector<string> &numbers);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  solve();

  return 0;
}

void solve() {
  int k, n;
  int diff;
  vector<string> numbers;

  cin >> k >> n;
  diff = n - k;
  for (int i = 0; i < k; ++i) {
    string number;
    cin >> number;
    numbers.push_back(number);
  }

  sort(numbers.begin(), numbers.end(), cmp);

  string maxNum = getMaxNum(numbers);

  for (const string &number : numbers) {
    while (diff > 0 && number == maxNum) {
      cout << number;
      diff--;
    }
    cout << number;
  }
}

string getMaxNum(const vector<string> &numbers) {
  int maxNum = 0;
  for (const string &number : numbers) {
    maxNum = max(maxNum, stoi(number));
  }
  return to_string(maxNum);
}

bool cmp(const string &num1, const string &num2) {
  if (num1 == num2) return true;
  return num1 + num2 > num2 + num1;
}