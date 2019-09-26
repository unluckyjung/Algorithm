#include <bits/stdc++.h>
using namespace std;

//7576 토마토

int board[1002][1002];
int dist[1002][1002];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>> q;
int n, m;
int MAX = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;

	memset(dist, -1, sizeof(dist));
	//거리를 전부 -1로 세팅해줌.


	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
			if (board[i][ii] == 1) {
				//핵심부분
				dist[i][ii] = 0;  q.push({ i,ii });
				//익은 토마토가 있는경우 dist의 해당좌표를 0으로 표시하고 큐에 넣음.
			}
		}
	}

	while (!q.empty()) {
		//핵심부분
		auto cur = q.front(); q.pop();
		//FIFO 방식이라, 익은 토마토들이 번갈아가면서 근처를 익히기 시작함.

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if (board[nx][ny] == -1 or dist[nx][ny] != -1) continue;
			//board에서 -1은 토마토가 없는곳, dist가 -1이 아니라면, 방문한 곳이라 pass

			dist[nx][ny] = dist[cur.first][cur.second] + 1 ; q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			MAX = max(MAX, dist[i][ii]);
			//MAX 선언값은 0, dist의 선언값은 -1이므로
			//처음부터 전부 사과가 익혀져있어 이동하지 않았을때 MAX는 0이 되어짐.
		}
	}
	

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			if (board[i][ii] == 0 and dist[i][ii] == -1) {
				//안익은 사과가 존재했으나, 해당 위치가 -1 이라는것은 익혀진적이 없다는것.
				cout << -1; return 0;
			}
		}
	}

	cout << MAX;

	return 0;
}