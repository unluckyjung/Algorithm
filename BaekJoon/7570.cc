#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 2;
int dp[MAX];
int studentCount, studentNumber;
int chainMaxLIS;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> studentCount;

  for (int i = 0; i < studentCount; ++i) {
    cin >> studentNumber;
    dp[studentNumber] = dp[studentNumber - 1] + 1;
    chainMaxLIS = max(chainMaxLIS, dp[studentNumber]);
  }

  cout << studentCount - chainMaxLIS << "\n";

  return 0;
}
