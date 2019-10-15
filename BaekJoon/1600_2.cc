#include <bits/stdc++.h>
using namespace std;
//백준 말이 되고픈 원숭이
//https://www.acmicpc.net/problem/1600

//점프
int hdx[] = { -1,1,2,2,1,-1,-2,-2 };
int hdy[] = { 2,2,1,-1,-2,-2,-1,1 };

//일반 상하좌우
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int k;
int n, m;

int board[201][201];
bool visit[201][201][32];	//뒤의 32은 점프 사용여부.


void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>>q;
	//좌표값 2개, 이동거리, 점프횟수를 큐에 넣음.
	visit[0][0][0] = true;
	q.push({ { 0,0 }, { 0,0 } });

	while (!q.empty()) {
		auto cur = q.front();	q.pop();
		int curx = cur.first.first;
		int cury = cur.first.second;

		int cnt = cur.second.first;
		int jump = cur.second.second;

		if (curx == n - 1 and cury == m - 1) {
			cout << cnt; return;
		}

		if (k > jump) {
			//점프 횟수가 k보다 작다면 점프가 가능. 0부터 시작이니.
			for (int dir = 0; dir < 8; ++dir) {
				int nx = curx + hdx[dir];
				int ny = cury + hdy[dir];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
				if (board[nx][ny] == 1)continue;
				if (visit[nx][ny][jump + 1])continue;
				//점프횟수가 +1 된 visit에서 이미 방문한곳인지 확인.
				visit[nx][ny][jump + 1] = true;
				q.push({ {nx,ny},{cnt + 1,jump + 1} });
			}
		}

		for (int dir = 0; dir < 4; ++dir) {
			int nx = curx + dx[dir];
			int ny = cury + dy[dir];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if (board[nx][ny] == 1)continue;
			if (visit[nx][ny][jump])continue;
			visit[nx][ny][jump] = true;
			q.push({ {nx,ny},{cnt + 1,jump} });
		}
	}
	cout << -1; return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> k;
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
		}
	}

	bfs();

	return 0;
}