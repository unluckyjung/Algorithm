#include <bits/stdc++.h>

using namespace std;

const int START_TYPE = 1;
const int END_TYPE = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  vector<pair<int, int>> spots;

  int start, end;
  while (t--) {
    cin >> start >> end;
    spots.push_back({start, START_TYPE});
    spots.push_back({end, END_TYPE});
  }

  sort(spots.begin(), spots.end());

  int answer = 0;
  int conflictCount = 0;
  for (auto spot : spots) {
    if (spot.second == START_TYPE) {
      conflictCount++;
      answer = max(answer, conflictCount);
    } else {
      conflictCount--;
    }
  }

  cout << answer << "\n";
  return 0;
}
