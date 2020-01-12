#include<bits/stdc++.h>
using namespace std;

int board[500001][2];

queue<pair<int, int>> q;
int cnt;
int n, k;

int subin, sister;
int day;


void sister_move() {
	while (1) {
		day++;
		k += day;

		if (k > 500000) {
			cout << -1 << "\n";
			exit(0);
		}

		if (board[k][0] == -1 && board[k][1] == -1)continue;
		if (board[k][0] > day&& board[k][1] > day)continue;

		if (board[k][0] == day or board[k][1] == day) {
			cout << day << "\n";
			exit(0);
		}

		if (day % 2 == 0 && board[k][0] != -1) {
			cout << max(day,board[k][0]) << "\n";
			exit(0);
		}

		if (day % 2 != 0 && board[k][1] != -1) {
			cout << max(day, board[k][1]) << "\n";
			exit(0);
		}

	}
}

void bfs() {
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cur_dx = cur.first;
		int cur_day = cur.second;
		int arr[] = { cur_dx - 1,cur_dx + 1, cur_dx * 2 };
		for (int dir = 0; dir < 3; ++dir) {
			int nx = arr[dir];
			if (nx < 0 or nx >500000)continue;
			if ((cur_day + 1) % 2 == 0) {
				if (board[nx][0] != -1)continue;
				board[nx][0] = cur_day + 1;
				q.push({ nx, cur_day + 1 });
			}
			else {
				if (board[nx][1] != -1)continue;
				board[nx][1] = cur_day + 1;
				q.push({ nx, cur_day + 1 });
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
	board[n][1] = 0;
	q.push({ n , 0 });
	bfs();
	sister_move();

	return 0;
}