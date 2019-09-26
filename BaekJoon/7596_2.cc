#include <bits/stdc++.h>
using namespace std;

//7569 토마토

#define H get<0>
#define X get<1>
#define Y get<2>
//get<0>(cur) 하기 귀찮아서 define

int board[102][102][102];
int dist[102][102][102];

//int dh[] = { -1,1 };	//위 아래를 탐색하는 dh도 필요하다.
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 }; 
//위 방법보다 이 방법이 더 직관적이고 좋다.
//1697

queue<tuple<int, int, int>> q;
int n, m, h;
int MAX = 0;


int main()
{

	memset(dist, -1, sizeof(dist));

	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			for (int iii = 0; iii < m; ++iii) {
				cin >> board[i][ii][iii];
				if (board[i][ii][iii] == 1) {
					dist[i][ii][iii] = 0; q.push({ i,ii,iii });
				}
			}
		}
	}


	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 6; ++dir) {
			int nh = H(cur) + dh[dir];
			int nx = X(cur) + dx[dir];
			int ny = Y(cur) + dy[dir];

			if (nh < 0 or nh >= h or nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (board[nh][nx][ny] == -1 or dist[nh][nx][ny] != -1)continue;
			dist[nh][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1; q.push({ nh,nx,ny });
		}

	}



	for (int i = 0; i < h; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			for (int iii = 0; iii < m; ++iii) {
				MAX = max(MAX, dist[i][ii][iii]);
				if (board[i][ii][iii] == 0 and dist[i][ii][iii] == -1) {
					//안익은 사과가 있었고 and 그 해당사과에 접근된적이 없다면 -1
					cout << -1; return 0;
				}
			}
		}
	}
	cout << MAX;



	return 0;
}