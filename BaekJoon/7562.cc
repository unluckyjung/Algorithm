#include <bits/stdc++.h>
using namespace std;

//7562 나이트의 이동

int dist[301][301];

int dx[] = { -1,1,2,2,1,-1,-2,-2 };
int dy[] = { 2,2,1,-1,-2,-2,-1,1 };

int start_x, start_y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int size;
		cin >> size;

		memset(dist, -1, sizeof(dist));

		queue<pair<int, int>>q;

		cin >> start_x >> start_y;
		dist[start_x][start_y] = 0;	q.push({ start_x, start_y });

		pair<int, int> destination;
		cin >> destination.first >> destination.second;
		//목적지 좌표를 받아서 넣어둔다.

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			if (cur.first == destination.first and cur.second == destination.second) {
				cout << dist[cur.first][cur.second] << "\n";
				break;
			}

			for (int dir = 0; dir < 8; ++dir) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 or nx >= size or ny < 0 or ny >= size)continue;
				if (dist[nx][ny] != -1) continue;
				//-1이 아닌것들은 방문한곳.
				dist[nx][ny] = dist[cur.first][cur.second] + 1;	q.push({ nx,ny });
			}
		}
	}

	return 0;

}