#include <bits/stdc++.h>
using namespace std;
//백준 1600 말이 되고픈 원숭이
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
int dist[201][201][32];	//뒤의 32은 스킬 사용여부.


void bfs(void) {
	queue<pair<pair<int, int>, int>>q;
	dist[0][0][k] = 0;	q.push({ {0,0},k });
	//처음 좌표 0,0, 그리고 점프 가능횟수[k]를 0으로 만들고,
	//큐에다가 해당 좌표와 점프 가능횟수를 넣어서 보냄.

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		auto x = cur.first.first;
		auto y = cur.first.second;
		auto skill = cur.second;

		if (x == n - 1 and y == m - 1) {
			cout << dist[x][y][skill];
			return;
		}

		if (skill) {
			//점프가 가능하다면
			for (int dir = 0; dir < 8; ++dir) {
				int nx = x + hdx[dir];
				int ny = y + hdy[dir];
				//점프 이동 값을 nx와 ny에 넣어둠.

				if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
				if (board[nx][ny] == 1)continue;
				//해당 좌표가 막힌곳인지 확인함.
				if (dist[nx][ny][skill - 1] != -1)continue;
				//점프를 해서 가려는곳이
				//현재 점프가능횟수 -1 보드에서 이미 간곳인지 확인함.

				dist[nx][ny][skill - 1] = dist[x][y][skill] + 1;
				//새로운 보드에다가 현재까지 이동한거리 + 1을 넣어줌.

				q.push({ {nx,ny},skill - 1 });
				//좌표와, 스킬 사용 가능횟수를 큐에 넣음.
			}
		}
		//점프가 가능하던, 불가능하던 4방면은 항상 갈 수 있음.
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (board[nx][ny] == 1)continue;
			if (dist[nx][ny][skill] != -1)continue;

			dist[nx][ny][skill] = dist[x][y][skill] + 1;
			//이곳에서는 현재 보드에다가 이동한거리 +1을 넣어줌.
			q.push({ { nx,ny }, skill });

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
	//입력 n과 m이 바뀌어져 있었음. 이거 캐치못해서 한참걸림.
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
		}
	}

	//거리값를 다 -1로 초기화 시켜둠.
	memset(dist, -1, sizeof(dist));
	bfs();

	return 0;
}