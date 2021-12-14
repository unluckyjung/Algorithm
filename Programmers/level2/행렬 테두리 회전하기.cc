#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[102][102];
vector<int> answer;

void init() {
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < m; ++ii) {
      board[i][ii] = cnt++;
    }
  }
}

void solve(int x1, int y1, int x2, int y2) {
  deque<int> q;
  int minValue = INT_MAX;

  for (int i = y1; i <= y2; ++i) {
    q.push_back(board[x1][i]);
    minValue = min(minValue, board[x1][i]);
  }

  for (int i = x1 + 1; i <= x2; ++i) {
    q.push_back(board[i][y2]);
    minValue = min(minValue, board[i][y2]);
  }

  for (int i = y2 - 1; i >= y1; --i) {
    q.push_back(board[x2][i]);
    minValue = min(minValue, board[x2][i]);
  }

  for (int i = x2 - 1; i > x1; --i) {
    q.push_back(board[i][y1]);
    minValue = min(minValue, board[i][y1]);
  }

  answer.push_back(minValue);
  q.push_front(q.back());
  q.pop_back();

  for (int i = y1; i <= y2; ++i) {
    board[x1][i] = q.front();
    q.pop_front();
  }

  for (int i = x1 + 1; i <= x2; ++i) {
    board[i][y2] = q.front();
    q.pop_front();
  }

  for (int i = y2 - 1; i >= y1; --i) {
    board[x2][i] = q.front();
    q.pop_front();
  }

  for (int i = x2 - 1; i > x1; --i) {
    board[i][y1] = q.front();
    q.pop_front();
  }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  n = rows;
  m = columns;
  init();

  for (vector<int> query : queries) {
    solve(query[0] - 1, query[1] - 1, query[2] - 1, query[3] - 1);
  }
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  solution(6, 6, {{2, 2, 5, 4},
                  {3, 3, 6, 6},
                  {5, 1, 6, 3}});

  return 0;
}
