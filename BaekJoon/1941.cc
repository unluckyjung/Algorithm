#include <bits/stdc++.h>

#define pii pair<int,int>
using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

char board[5][5];
bool canGo[5][5];
bool visited[5][5];

vector<int> member(25 - 7, 0);

queue<pii > location;

int n = 5;

void init() {
  memset(canGo, false, sizeof(canGo));
  memset(visited, false, sizeof(visited));
  location = queue<pii >();
}

bool locationCheck() {
  int memberCount = 0;

  while (!location.empty()) {
    pii cur = location.front();
    location.pop();
    memberCount++;

    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 or nx >= n or ny < 0 or ny >= n)continue;
      if (visited[nx][ny])continue;
      if (!canGo[nx][ny])continue;

      visited[nx][ny] = true;
      location.push({nx, ny});
    }
  }

  return memberCount == 7;
}

bool teamCheck() {
  int Y_count = 0;

  int x, y;
  for (int i = 0; i < 25; ++i) {
    if (member[i] != 1)continue;
    x = i / n;
    y = i % n;
    if (board[x][y] == 'Y') Y_count++;

    canGo[x][y] = true;
    if (Y_count >= 4) return false;
  }

  visited[x][y] = true;
  location.push({x, y});
  return locationCheck();
}

int solve() {
  int answer = 0;

  do {
    init();
    if (teamCheck()) answer++;
  } while (next_permutation(member.begin(), member.end()));

  return answer;
}

void input() {
  string line;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    for (int ii = 0; ii < n; ++ii) {
      board[i][ii] = line[ii];
    }
  }
  for (int i = 0; i < 7; ++i) member.push_back(1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  input();
  cout << solve() << "\n";

  return 0;
}
