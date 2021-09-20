#include <bits/stdc++.h>

using namespace std;

vector<int> node[102];
int userDist[102][102];
bool isVisited[102];
int n, m;

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

void bfs(int from, int to) {
  queue<int> q;
  memset(isVisited, false, sizeof(isVisited));
  isVisited[from] = true;
  q.push(from);
  int count = 0;

  while (!q.empty()) {
    int qSize = q.size();
    while (qSize--) {
      int cur = q.front();
      q.pop();

      if (cur == to) {
        userDist[from][to] = count;
        return;
      }

      for (int next : node[cur]) {
        if (isVisited[next]) continue;
        isVisited[next] = true;
        q.push(next);
      }
    }
    count++;
  }
}

void sol(int from) {
  for (int target = 1; target <= n; ++target) {
    if (target == from) continue;
    bfs(from, target);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

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