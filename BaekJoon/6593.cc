#include <bits/stdc++.h>
using namespace std;
//백준 6593 상범빌딩
//https://www.acmicpc.net/problem/6593

#define H get<0>
#define X get<1>
#define Y get<2>

//vector<vector<string>> board(31);
//전역으로 하고 clear시 board 크기도 같이 초기화 되어 오류난다.
int dist[31][31][31];

int dh[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };

int h, n, m;


void bfs(vector<vector<string>> &board) {

	queue<tuple<int, int, int>> q;


	for (int i = 0; i < h; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			string str;
			cin >> str;

			board[i].push_back(str); 

			for (int iii = 0; iii < (int)str.size(); ++iii) {
				if (str[iii] == 'S') {
					dist[i][ii][iii] = 0;
					q.push({ i,ii,iii });	break;
				}
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (board[H(cur)][X(cur)][Y(cur)] == 'E') {
			cout << "Escaped in " << dist[H(cur)][X(cur)][Y(cur)] << " minute(s).\n";
			return;
		}
		for (int dir = 0; dir < 6; ++dir) {
			int nh = H(cur) + dh[dir];
			int nx = X(cur) + dx[dir];
			int ny = Y(cur) + dy[dir];

			if (nh < 0 or nh >= h or nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			//if (board[nh][nx][ny] != '.')continue;
			//. 이 아닐떄 continue 시키면 #의 경우도 continue 되어서 다 trap되어버림.
			if (board[nh][nx][ny] == '#')continue;
			if (dist[nh][nx][ny] != -1)continue;
			dist[nh][nx][ny] = dist[H(cur)][X(cur)][Y(cur)] + 1; q.push({ nh,nx,ny });
		}
	}

	cout << "Trapped!\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> h >> n >> m;
		if (h == 0 and n == 0 and m == 0)return 0;
		
		memset(dist, -1, sizeof(dist));
		vector<vector<string>> board(31);
		//매번 2차원 vector를 새로 만들어주어야한다.

		bfs(board);
	}
	return 0;
}