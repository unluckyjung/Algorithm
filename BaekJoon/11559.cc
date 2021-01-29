#include<bits/stdc++.h>
using namespace std;

char board[12][6];
bool visited[12][6];

queue<pair<int, int>> q;
queue<pair<int, int>> bq;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n = 12, m = 6;
int boom_cnt;
bool isCanBoom;
const int boomConnectCount = 4;

void bfs();

void relocation() {
	for (int ii = 0; ii < m; ++ii) {
		queue<char> buff;
		for (int i = n; i >= 0; --i) {
			if (board[i][ii] == '.') continue;
			buff.push(board[i][ii]);
		}

		for (int i = n; i >= 0; --i) {
			if (!buff.empty()) {
				board[i][ii] = buff.front();
				buff.pop();
			}
			else board[i][ii] = '.';
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
				if (board[i][ii] == '.' or visited[i][ii])continue;
				visited[i][ii] = true;
				q.push({ i, ii });
				bfs();
			}
		}
		if (isCanBoom) {
			isCanBoom = false;
			boom_cnt++;
			relocation();
			memset(visited, false, sizeof(visited));
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
			if (visited[nx][ny])continue;
			if (board[nx][ny] != board[cur.first][cur.second])continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	while (!bq.empty()) {
		if (same_cnt >= boomConnectCount) {
			isCanBoom = true;
			auto bq_cur = bq.front();
			board[bq_cur.first][bq_cur.second] = '.';
		}
		bq.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	input();
	solve();
	cout << boom_cnt;
	return 0;
}