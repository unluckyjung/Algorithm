#include<bits/stdc++.h>
using namespace std;
//백준 다리만들기 2146
//https://www.acmicpc.net/problem/2146

int n;
int board[102][102];
bool visit[102][102];


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int land_num = 1;

int result = INT_MAX;

void bfs_land(int i, int ii) {
	board[i][ii] = land_num;
	queue<pair<int, int>> q;
	visit[i][ii] = true; q.push({ i,ii });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first; int y = cur.second;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or nx >= n) continue;
			if (board[nx][ny] != 1 or visit[nx][ny])continue;
			visit[nx][ny] = true;	board[nx][ny] = land_num; q.push({ nx,ny });
		}
	}
	land_num++;
}

void bfs_sea(int i, int ii) {
	queue<tuple<int, int, int>> q;

	int check = board[i][ii];
	visit[i][ii] = true;  q.push({ i,ii, 0 });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = get<0>(cur);
		int y = get<1>(cur);
		int distance = get<2>(cur);

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or ny >= n)continue;
			if (visit[nx][ny])continue;

			if (board[nx][ny] >= 1) {
				if (check == board[nx][ny]) continue;
				result = min(result, distance); continue;
			}
			visit[nx][ny] = true;
			q.push({ nx, ny , distance + 1 });

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cin >> board[i][ii];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			if (board[i][ii] == 1) {
				if (!visit[i][ii]) bfs_land(i, ii);
				//만약 섬인경우. 섬을 번호로 바꿈.

			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			if (board[i][ii] >= 1) {	//실수한 부분========
				//이전에 1인 경우에만 처리해놓음.
				memset(visit, false, sizeof(visit));
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir];
					int ny = ii + dy[dir];
					if (board[nx][ny] == 0) bfs_sea(i, ii);
				}
			}
		}
	}


	cout << result;
	return 0;
}