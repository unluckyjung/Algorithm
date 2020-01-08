#include<bits/stdc++.h>
using namespace std;

int board[101][101];
bool visit[101][101];
bool light[101][101];
int cnt;

map<pair<int, int>, queue<pair<int, int> > >light_m;
queue<pair<int, int> > lq;
queue<pair<int, int> > q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;

void output() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cout << visit[i][ii];
		}
		cout << "\n";
	}
}

void light_on(pair<int, int> k) {
	while (!light_m[k].empty()) {
		auto cur = light_m[k].front();	light_m[k].pop();
		if (!light[cur.first][cur.second]) {
			light[cur.first][cur.second] = true;
			lq.push({ cur.first, cur.second });
			cnt++;
		}
	}
}

void bfs() {
	if (q.empty())return;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		//light_on(cur);

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 or nx >= n or ny < 0 or ny >= n)continue;
			if (visit[nx][ny])continue;
			if (!light[nx][ny])continue;
			visit[nx][ny] = true;
			light_on({ nx,ny });
			q.push({ nx,ny });
		}
	}
	while (!lq.empty()) {
		auto cur = lq.front();	lq.pop();
		if (visit[cur.first][cur.second])continue;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 or nx >= n or ny < 0 or ny >= n)continue;
			if (visit[nx][ny]) {
				visit[cur.first][cur.second] = true;
				light_on({ cur.first,cur.second });
				q.push({ cur.first, cur.second });
				break;
			}
		}
	}
	bfs();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		light_m[{a - 1, b - 1}].push({ c - 1,d - 1 });
	}

	visit[0][0] = true;
	light[0][0] = true;

	light_on({ 0,0 });
	lq.push({ 0,0 });
	q.push({ 0,0 });
	cnt++;

	bfs();

	//output();
	cout << cnt;

	return 0;
}