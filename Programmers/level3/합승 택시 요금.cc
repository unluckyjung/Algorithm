#include <bits/stdc++.h>

using namespace std;

const int SECTION_MAX = 202;
const int INF = 1e8 + 2;
int dist[SECTION_MAX][SECTION_MAX];

void floyd(int n, const vector<vector<int>> &fares) {
  for (int i = 1; i <= n; ++i) {
    for (int ii = 1; ii <= n; ++ii) {
      if (i == ii) continue;
      dist[i][ii] = INF;
    }
  }

  for (const vector<int> &fare : fares) {
    int cost = fare[2];
    dist[fare[0]][fare[1]] = cost;
    dist[fare[1]][fare[0]] = cost;
  }

  for (int visited = 1; visited <= n; ++visited) {
    for (int st = 1; st <= n; ++st) {
      for (int ed = 1; ed <= n; ++ed) {
        dist[st][ed] = min(dist[st][ed], dist[st][visited] + dist[visited][ed]);
      }
    }
  }
}

int solution(int n, int startSpot, int aHome, int bHome, vector<vector<int>> fares) {
  int answer = INF;

  floyd(n, fares);
  for (int midSpot = 1; midSpot <= n; ++midSpot) {
    answer = min(answer, dist[startSpot][midSpot] + dist[midSpot][aHome] + dist[midSpot][bHome]);
  }

  return answer;
}
