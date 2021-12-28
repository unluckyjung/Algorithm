#include <bits/stdc++.h>

using namespace std;

struct st {
    int x;
    int y;
    int dist;
};

vector<string> board;
bool visited[5][5];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool isValidateHuman(int sX, int sY) {
  memset(visited, false, sizeof(visited));
  queue<st> q;
  visited[sX][sY] = true;
  q.push({sX, sY, 0});

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (board[cur.x][cur.y] == 'P') {
      if (cur.dist > 0 && cur.dist <= 2) {
        return false;
      }
    }

    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];

      if (nx < 0 or nx >= 5 or ny < 0 or ny >= 5) continue;
      if (visited[nx][ny]) continue;
      if (board[nx][ny] == 'X') continue;

      visited[nx][ny] = true;
      q.push({nx, ny, cur.dist + 1});
    }
  }
  return true;
}

bool isCan() {
  for (int i = 0; i < 5; ++i) {
    for (int ii = 0; ii < 5; ++ii) {
      if (board[i][ii] != 'P') continue;
      if (isValidateHuman(i, ii)) continue;
      return false;
    }
  }
  return true;
}

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;

  for (auto place : places) {
    board = place;
    if (isCan()) answer.push_back(1);
    else answer.push_back(0);
  }

  return answer;
}