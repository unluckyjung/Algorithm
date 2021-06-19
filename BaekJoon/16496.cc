#include <bits/stdc++.h>

using namespace std;

void solve();

bool cmp(const string &num1, const string &num2);

bool isOnlyZero(const vector<string> &numbers);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  solve();

  return 0;
}

void solve() {
  int n;
  vector<string> numbers;

  cin >> n;
  while (n--) {
    string number;
    cin >> number;
    numbers.push_back(number);
  }

  sort(numbers.begin(), numbers.end(), cmp);

  if (isOnlyZero(numbers)) {
    cout << "0";
    return;
  }

  for (const string &number : numbers) {
    cout << number;
  }
}

bool cmp(const string &num1, const string &num2) {
  if (num1 == num2) return true;
  return num1 + num2 > num2 + num1;
}

bool isOnlyZero(const vector<string> &numbers) {
  return numbers[0] == "0";
}

// bool isOnlyZero(const vector <string> &numbers) {
//   for (const string &number : numbers) {
//     if (number != "0") return false;
//   }
//   return true;
// }