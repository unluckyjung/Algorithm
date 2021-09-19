#include <bits/stdc++.h>

using namespace std;

void solution(const vector<int> &numbers) {
  string num1 = "";
  string num2 = "";

  bool flag = true;
  int zeroCount = 0;
  for (int num : numbers) {
    if (num == 0) {
      zeroCount++;
      continue;
    }
    if (flag) {
      num1 += to_string(num);
      flag = false;
    } else {
      num2 += to_string(num);
      flag = true;
    }
  }
  while(zeroCount--){
    if (flag) {
      num1.insert(1, "0");
      flag = false;
    } else {
      num2.insert(1, "0");
      flag = true;
    }
  }

  cout << stoi(num1) + stoi(num2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
//  freopen("input.txt", "r", stdin);

  int n;
  while (true) {
    cin >> n;
    if (n == 0) return 0;
    vector<int> numbers;
    while (n--) {
      int num;
      cin >> num;
      numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    solution(numbers);
  }
}
