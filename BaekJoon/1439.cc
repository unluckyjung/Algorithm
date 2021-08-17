#include <bits/stdc++.h>

using namespace std;

void chainingCheck(char num, int &chainingZeroCount, int &chainingOneCount, char &beforeNumber);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  int chainingZeroCount = 0;
  int chainingOneCount = 0;

  char beforeNumber;

  for (int i = 0; i < (int)str.size(); ++i) {
    char num = str[i];
    if (i == 0) {
      chainingCheck(num, chainingZeroCount, chainingOneCount, beforeNumber);
    } else {
      if (num == beforeNumber) continue;
      chainingCheck(num, chainingZeroCount, chainingOneCount, beforeNumber);
    }
  }

  cout << min(chainingZeroCount, chainingOneCount);
  return 0;
}

void chainingCheck(char num, int &chainingZeroCount, int &chainingOneCount, char &beforeNumber) {
  if (num == '0') {
    chainingZeroCount++;
    beforeNumber = '0';
  } else {
    chainingOneCount++;
    beforeNumber = '1';
  }
}
