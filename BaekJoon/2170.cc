#include <bits/stdc++.h>

using namespace std;

const int START = 0;
const int END = 1;

int n;
int answer;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  cin >> n;
  vector<pair<int, int>> spots;

  while (n--) {
    int st, ed;
    cin >> st >> ed;
    spots.push_back({st, START});
    spots.push_back({ed, END});
  }

  sort(spots.begin(), spots.end());

  int spotCount = 0;
  int frontSpot = 0;
  for (auto spot : spots) {
    if (spot.second == START) {
      if (spotCount == 0) frontSpot = spot.first;
      spotCount++;
    } else {
      spotCount--;
      if (spotCount == 0) answer += spot.first - frontSpot;
    }
  }

  cout << answer << "\n";

  return 0;
}
