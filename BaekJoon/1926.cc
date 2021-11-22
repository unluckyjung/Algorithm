#include<bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int pic[502][502];
bool visited[502][502];

int n, m;
int picMaxSize, picCount;

void floodFIll(const int &i, const int &ii) {
  queue<pair<int, int>> q;
  visited[i][ii] = true;
  q.push({i, ii});

  int curPicSize = 0;
  picCount++;

  while (!q.empty()) {
    curPicSize++;
    auto curpic = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int nx = curpic.first + dx[dir];
      int ny = curpic.second + dy[dir];
      if (visited[nx][ny] or pic[nx][ny] == 0)continue;
      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  picMaxSize = max(picMaxSize, curPicSize);
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < m; ++ii) {
      cin >> pic[i][ii];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  input();

  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < m; ++ii) {
      if (visited[i][ii] or pic[i][ii] == 0) continue;
      floodFIll(i, ii);
    }
  }

  cout << picCount << "\n" << picMaxSize;

  return 0;
}

