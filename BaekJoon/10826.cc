#include <bits/stdc++.h>

using namespace std;

string memo[10002];

string sum(string num1, string num2) {
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());

  int maxLen = max((int) num1.size(), (int) num2.size());

  while (num1.size() < maxLen) {
    num1 += "0";
  }

  while (num2.size() < maxLen) {
    num2 += "0";
  }

  int carry = 0;
  string result;
  for (int i = 0; i < maxLen; ++i) {
    int tmp = num1[i] - '0' + num2[i] - '0' + carry;
    result += to_string(tmp % 10);
    carry = tmp / 10;
  }

  if (carry == 1) {
    result += "1";
  }
  reverse(result.begin(), result.end());

  return result;
}

string fibo(int num) {
  if (num < 2) return to_string(num);
  if (!memo[num].empty()) return memo[num];

  return memo[num] = sum(fibo(num - 1), fibo(num - 2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  int n;
  cin >> n;

  cout << fibo(n) << "\n";

  return 0;
}
