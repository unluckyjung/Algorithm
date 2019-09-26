#include <bits/stdc++.h>
using namespace std;

//1012 유기농 배추
int board[52][52];
bool visit[52][52];

int n, m;
int k;
int x, y;


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		//초기화를 해줘야한다.
		memset(board, 0, sizeof(board));
		memset(visit, false, sizeof(visit));

		cin >> n >> m >> k;
		while (k--) {
			cin >> x >> y;
			board[x][y] = 1;
		}
		int num = 0;

		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < m; ++ii) {
				if (visit[i][ii] or board[i][ii] == 0) continue;
				queue<pair<int, int>> q;
				visit[i][ii] = true; q.push({ i,ii });
				num++;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();

					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (visit[nx][ny] or board[nx][ny] == 0) continue;
						if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
						visit[nx][ny] = true; q.push({ nx,ny });
					}
				}
			}
		}
		cout << num << "\n";
	}

	return 0;
}