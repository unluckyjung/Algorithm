#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int board[52][52];
bool visited[52][52];

int n, m;
int k;

void bfs(int &num, const int &i, const int &ii);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    memset(board, 0, sizeof(board));
    memset(visited, false, sizeof(visited));

    cin >> n >> m >> k;
    while (k--) {
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
    }

    int num = 0;
    for (int i = 0; i < n; ++i) {
      for (int ii = 0; ii < m; ++ii) {
        if (visited[i][ii] or board[i][ii] == 0) continue;
        bfs(num, i, ii);
      }
    }
    cout << num << "\n";
  }

  return 0;
}

void bfs(int &num, const int &i, const int &ii) {
  queue<pair<int, int>> q;
  visited[i][ii] = true;
  q.push({i, ii});
  num++;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (visited[nx][ny] or board[nx][ny] == 0) continue;
      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}
