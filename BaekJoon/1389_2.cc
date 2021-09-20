#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> node[102];
int userDist[102][102];
bool isVisited[102];
const int INF = 1e8;

void getAnswer() {
  vector<pair<int, int>> vec;
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int ii = 1; ii <= n; ++ii) {
      if (i == ii) continue;
      sum += userDist[i][ii];
    }
    vec.push_back({sum, i});
  }
  sort(vec.begin(), vec.end());
  cout << vec[0].second << "\n";
}

void dfs(int from, int target, int cur, int depth) {
  for (int next : node[cur]) {
    if (isVisited[next]) continue;
    if (next == target) {
      userDist[from][target] = min(userDist[from][target], depth);
      return;
    }
    isVisited[next] = true;
    dfs(from, target, next, depth + 1);
    isVisited[next] = false;
  }
}


void sol(int from) {
  for (int target = 1; target <= n; ++target) {
    if (target == from) continue;
    isVisited[from] = true;
    dfs(from, target, from, 1);
    isVisited[from] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int ii = 1; ii <= n; ++ii) {
      userDist[i][ii] = INF;
    }
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    sol(i);
  }
  getAnswer();

  return 0;
}