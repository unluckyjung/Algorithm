#include <bits/stdc++.h>
using namespace std;
//백준 빙산 2573
//https://www.acmicpc.net/problem/2573

int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int year;

int board[301][301];
bool visit[301][301];

int num;
map<pair<int, int>, int > water;

void bfs(int i, int ii) {
	queue<pair<int, int>> q;
	visit[i][ii] = true;	q.push({ i, ii });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (board[nx][ny] <= 0) {
				//상하 좌우를 따져볼때 0보다 작은 수인경우 물
				water[{cur.first, cur.second}]++;
				//물에 맞닿는 좌표를 넣어두고, 값을 증가시킨다.

				//water[{cur.x, cur.y}];
				//#define first x 해 놓아도
				//여기서만 안된다 이유 모르겠음.
				continue;
			}
			if (visit[nx][ny])continue;
			visit[nx][ny] = true; q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
		}
	}

	while (1) {
		num = 0;
		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < m; ++ii) {
				if (board[i][ii] <= 0 or visit[i][ii])continue;
				num++;
				bfs(i, ii);
			}
		}
		if (num >= 2) {
			cout << year; return 0;
		}
		if (num == 0) {
			cout << 0;	return 0;
		}

		for (auto it : water) {
			board[it.first.first][it.first.second] -= it.second;
			//물에 맞닿는 좌표는, 맞닿은 물만큼 감소시켜 빙산을 녹인다.
		}
		water.clear();
		memset(visit, false, sizeof(visit));
		year++;

	}

	return 0;
}