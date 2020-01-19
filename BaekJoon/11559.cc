#include<bits/stdc++.h>
using namespace std;

char board[12][6];
bool visit[12][6];

queue<pair<int, int>>q;
queue<pair<int, int>>bq;
bool boom;
int boom_cnt;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


int n = 12, m = 6;

void bfs();

void relocation() {
	for (int i = 10; i >= 0; --i) {
		for (int ii = 0; ii < m; ++ii) {
			char ch = board[i][ii];
			int ni = i;
			while (1) {
				if (ni == 11)break;
				if (board[ni + 1][ii] != '.')break;
				ni++;
			}
			board[i][ii] = '.';
			board[ni][ii] = ch;
		}
	}
}
void input() {
	for (int i = 0; i < n; ++i) {
		string line; cin >> line;
		for (int ii = 0; ii < m; ++ii) {
			board[i][ii] = line[ii];
		}
	}
}

void solve() {
	while (1) {
		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < m; ++ii) {
				if (board[i][ii] == '.' or visit[i][ii])continue;
				visit[i][ii] = true;
				q.push({ i, ii });
				bfs();
			}
		}
		if (boom) {
			boom = false;
			boom_cnt++;
			relocation();
			memset(visit, false, sizeof(visit));
		}
		else return;
	}
}

void bfs() {
	int same_cnt = 0;
	while (!q.empty()) {
		same_cnt++;
		bq.push(q.front());
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (visit[nx][ny])continue;
			if (board[nx][ny] != board[cur.first][cur.second])continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}		
	}
	while (!bq.empty()) {
		if (same_cnt >= 4) {
			boom = true;
			auto bq_cur = bq.front();
			board[bq_cur.first][bq_cur.second] = '.';
		}
		bq.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();
	solve();
	cout << boom_cnt;
	return 0;
}