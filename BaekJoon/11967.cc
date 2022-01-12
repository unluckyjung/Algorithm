#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

bool isVisited[101][101], isLightOn[101][101];
int answer = 1;

map<pii, queue<pii>> switchMap;
queue<pii> lightQ, q;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;

void lightOn(pii k) {
  while (!switchMap[k].empty()) {
    auto cur = switchMap[k].front();
    switchMap[k].pop();

    if (!isLightOn[cur.first][cur.second]) {
      isLightOn[cur.first][cur.second] = true;
      lightQ.push({cur.first, cur.second});
      answer++;
    }
  }
}

void bfs() {
  if (q.empty()) return;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
      if (isVisited[nx][ny]) continue;
      if (!isLightOn[nx][ny]) continue;

      isVisited[nx][ny] = true;
      lightOn({nx, ny});
      q.push({nx, ny});
    }
  }

  while (!lightQ.empty()) {
    auto cur = lightQ.front();
    lightQ.pop();

    if (isVisited[cur.first][cur.second]) continue;

    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;

      if (isVisited[nx][ny]) {
        isVisited[cur.first][cur.second] = true;
        lightOn({cur.first, cur.second});
        q.push({cur.first, cur.second});
        break;
      }
    }
  }

  bfs();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  cin >> n >> m;
  while (m--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    switchMap[{a - 1, b - 1}].push({c - 1, d - 1});
  }

  isVisited[0][0] = true;
  isLightOn[0][0] = true;

  lightOn({0, 0});
  lightQ.push({0, 0});
  q.push({0, 0});

  bfs();
  cout << answer;

  return 0;
}