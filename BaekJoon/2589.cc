#include <bits/stdc++.h>
using namespace std;

char board[51][51];
int dist[51][51];
int n, m;

int answer;

queue<pair<int, int> > q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;
		for (int ii = 0; ii < m; ++ii) {
			board[i][ii] = line[ii];
		}
	}
}

void bfs() {
	while(!q.empty()) {
		pair<int, int> cur = q.front();	q.pop();
		answer = max(answer, dist[cur.first][cur.second]);
		
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (board[nx][ny] != 'L' || dist[nx][ny] != -1)continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}

void solve() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			if (board[i][ii] == 'W')continue;
			memset(dist, -1, sizeof(dist));
			dist[i][ii] = 0;
			q.push(make_pair(i, ii));
			bfs();
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}