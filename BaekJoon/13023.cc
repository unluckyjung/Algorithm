#include <bits/stdc++.h>

using namespace std;

vector<int> human[2002];
bool visited[2002];
int n, m;
bool findAnswer;

void dfs(int cur, int depth) {
  if (findAnswer) return;

  if (depth == 4) {
    findAnswer = true;
    return;
  }

  for (auto nxt : human[cur]) {
    if (visited[nxt])continue;
    visited[nxt] = true;
    dfs(nxt, depth + 1);
    visited[nxt] = false;

    if (findAnswer) return;
  }

}

int solve() {
  for (int i = 0; i < n; ++i) {
    visited[i] = true;
    dfs(i, 0);
    visited[i] = false;
    if (findAnswer) return 1;
  }
  return 0;
}

void input() {
  cin >> n >> m;
  int a, b;
  while (m--) {
    cin >> a >> b;
    human[a].push_back(b);
    human[b].push_back(a);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  input();
  cout << solve() << "\n";

  return 0;
}