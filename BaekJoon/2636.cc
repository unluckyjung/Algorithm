#include <bits/stdc++.h>
using namespace std;

int left_cheese[10000];
int time_cnt;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int board[101][101];
bool visit[101][101];

queue<pair<int, int > >cur_q;
queue<pair<int, int > >new_q;

int cheese_sum;
int n, m;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
			if (board[i][ii] == 1)left_cheese[0]++;
		}
	}
	visit[0][0] = true;
	cur_q.push(make_pair(0, 0));
}

void melt() {
	while (!cur_q.empty()) {
		pair<int, int> cur = cur_q.front();	cur_q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (visit[nx][ny])continue;
			visit[nx][ny] = true;
			if (board[nx][ny] == 0) cur_q.push(make_pair(nx, ny));
			else {
				board[nx][ny] = 0;
				new_q.push(make_pair(nx, ny));
			}
		}
	}
}


void solve() {
	melt();
	while (!(cur_q.empty() && new_q.empty())) {
		time_cnt++;
		left_cheese[time_cnt] = left_cheese[time_cnt - 1] - new_q.size();
		cur_q = new_q;
		while (!new_q.empty())	new_q.pop();
		melt();
	}
	cout << time_cnt << "\n" << left_cheese[time_cnt - 1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}