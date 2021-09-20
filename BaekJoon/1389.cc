#include <bits/stdc++.h>

using namespace std;

int dist[102][102];
const int INF = 1e8;
int n, m;

void printAnswer() {
  vector<pair<int, int>> ret;
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int ii = 1; ii <= n; ++ii) {
      sum += dist[i][ii];
    }
    ret.push_back({sum, i});
  }
  sort(ret.begin(), ret.end());
  cout << ret[0].second << "\n";
}


void solve() {
  for (int visited = 1; visited <= n; ++visited) {
    for (int from = 1; from <= n; ++from) {
      for (int to = 1; to <= n; ++to) {
        dist[from][to] = min(dist[from][to], dist[from][visited] + dist[visited][to]);
      }
    }
  }
  printAnswer();
}


void init() {
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int ii = 1; ii <= n; ++ii) {
      if (i == ii) continue;
      dist[i][ii] = INF;
    }
  }

  while (m--) {
    int s, e;
    cin >> s >> e;
    dist[s][e] = dist[e][s] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  solve();

  return 0;
}