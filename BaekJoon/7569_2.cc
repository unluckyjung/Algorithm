#include<bits/stdc++.h>
#define MAX 101

struct tomato {
	int h, x, y;
};
using namespace std;

int box[MAX][MAX][MAX];
//		h	n	m
int dist[MAX][MAX][MAX];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, h;
int ripe_tomato, blank, non_ripe_totmato;
int time_cnt;
queue<tomato> q;

void output() {
	cout << "\n\n";
	for (int i = 0; i < h; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			for (int iii = 0; iii < m; ++iii) {
				cout << dist[i][ii][iii] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void bfs() {
	while (!q.empty()) {
		tomato cur = q.front(); q.pop();
		time_cnt = max(time_cnt, dist[cur.h][cur.x][cur.y]);

		for (int next_height = -1; next_height <= 1; ++next_height) {
			int nh = cur.h + next_height;
			for (int dir = 0; dir < 4; ++dir) {
				//int nh = cur.h + next_height;
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];

				if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
				if (dist[cur.h][nx][ny] != -1)continue;
				if (box[cur.h][nx][ny] != 0)continue;
				
				dist[cur.h][nx][ny] = dist[cur.h][cur.x][cur.y] + 1;
				box[cur.h][nx][ny] = 1;	
				non_ripe_totmato--;
				q.push({ cur.h,nx,ny });
			}

			if (nh < 0 or nh >= h)continue;
			if (dist[nh][cur.x][cur.y] != -1)continue;
			if (box[nh][cur.x][cur.y] != 0)continue;

			dist[nh][cur.x][cur.y] = dist[cur.h][cur.x][cur.y] + 1;
			box[nh][cur.x][cur.y] = 1;

			non_ripe_totmato--;
			q.push({ nh,cur.x,cur.y });
		}
	}
}

void solve() {
	bfs();
	if (non_ripe_totmato) cout << -1;
	else cout << time_cnt;
}

void all_ripe_check() {
	if (ripe_tomato == m * n * h - blank) {
		cout << 0;
		exit(0);
	}
}

void input() {
	memset(dist, -1, sizeof(dist));

	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			for (int iii = 0; iii < m; ++iii) {
				cin >> box[i][ii][iii];

				if (box[i][ii][iii] == 1) {
					q.push({ i,ii,iii });
					dist[i][ii][iii] = 0;
					ripe_tomato++;
				}
				else if (box[i][ii][iii] == -1) {
					dist[i][ii][iii] = -2;
					blank++;
				}
				else non_ripe_totmato++;
			}
		}
	}
	all_ripe_check();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	input();
	solve();
	//output();

	return 0;
}