#include <bits/stdc++.h>
using namespace std;

int t;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n = 5, m = 9;
//m이 10이 아니라 9였다 똑바로 세기 -_-

int min_pin , min_move;
vector<string> board;


void dfs(vector<string> board, int cur_pin, int cur_move) {
	if (cur_pin <= min_pin) {
		if (min_pin == cur_pin) min_move = min(min_move, cur_move);
		else {
			min_pin = cur_pin;
			min_move = cur_move;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			if (board[i][ii] != 'o')continue;

			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = ii + dy[dir];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
				if (board[nx][ny] != 'o')continue;

				int nnx = nx + dx[dir];
				int nny = ny + dy[dir];
				if (nnx < 0 or nnx >= n or nny < 0 or nny >= m)continue;
				if (board[nnx][nny] != '.')continue;
				vector<string> next_board = board;

				next_board[i][ii] = '.';
				next_board[nx][ny] = '.';
				next_board[nnx][nny] = 'o';
				dfs(next_board, cur_pin - 1, cur_move + 1);

			}

		}
	}
}

void input() {
	cin >> t;
	while (t--) {
		board.clear();
		min_pin = 0;
		min_move = INT_MAX;

		string line;
		for (int i = 0; i < n; ++i) {
			cin >> line;
			board.push_back(line);
			for (int ii = 0; ii < m; ++ii) {
				if (line[ii] == 'o')min_pin++;
			}
		}
		dfs(board, min_pin, 0);
		cout << min_pin << " " << min_move << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	return 0;
}