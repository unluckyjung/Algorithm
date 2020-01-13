#include<bits/stdc++.h>
using namespace std;

int day;
int n, k;
int board[500001][2];
queue<pair<int, int > > q;

void sister_move() {
	while (1) {
		day++;
		k += day;
		if (k > 500000) {
			cout << -1 << "\n";
			exit(0);
		}

		if (day % 2 == 0) {
			if (board[k][0] == -1 or board[k][0] > day)continue;
			//cout << k << "\n";
			//cout << board[k][0] << "\n";
			cout << day << "\n";
			exit(0);
		}
		else {
			if (board[k][1] == -1 or board[k][1] > day)continue;
			cout << day << "\n";
			exit(0);
		}
	}
}

void bfs() {
	while (!q.empty()) {
		auto cur = q.front();	q.pop();
		int cur_nx = cur.first, next_day = cur.second + 1;

		int arr[] = { cur_nx - 1, cur_nx + 1, cur_nx * 2 };
		for (int dir = 0; dir < 3; ++dir) {
			int nx = arr[dir];
			if (nx < 0 or nx > 500000)continue;
			
			if (next_day % 2 == 0) {
				if (board[nx][0] != -1)continue;
				board[nx][0] = next_day;
				q.push({ nx, next_day });
			}
			else {
				if (board[nx][1] != -1)continue;
				board[nx][1] = next_day;
				q.push({ nx, next_day });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	if (n == k) {
		cout << 0 << "\n";
		return 0;
	}
	memset(board, -1, sizeof(board));
	board[n][0] = 0;
	//board[n][1] = 0;
	q.push({ n, 0 });

	bfs();
	sister_move();

	return 0;
}