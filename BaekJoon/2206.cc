#include<bits/stdc++.h>
using namespace std;

//2206 벽부시고 이동하기

vector<string> board;
int dist[1001][1001];

int n, m;
int MIN_distance = INT_MAX;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(void){
	queue<pair<int, int>>q;
	dist[0][0] = 0;  q.push({ 0,0 });

	while (!q.empty()) {
		auto cur = q.front();	q.pop();
		if (cur.first == n - 1 and cur.second == m - 1) {
			MIN_distance = min(MIN_distance, dist[cur.first][cur.second]);
			return;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (board[nx][ny] == 1 or dist[nx][ny] != -1)continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1; q.push({ nx,ny });
		}
		
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		board.push_back(str);
	}

	memset(dist, -1, sizeof(dist));
	bfs();

	cout << "\n\n";
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cout << board[i][ii] << " ";
		}
		cout << "\n";
	}


	cout << "\n\n";
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cout << dist[i][ii] << " ";
		}
		cout << "\n";
	}

	//for (int i = 0; i < n; ++i) {
	//	for (int ii = 0; ii < m; ++ii) {
	//		if (board[i][ii] == '1') {
	//			memset(dist, -1, sizeof(dist));
	//			board[i][ii] = '0';

	//			bfs();

	//			board[i][ii] = '1';
	//		}
	//	}
	//}

	if (MIN_distance == INT_MAX) {
		cout << -1;	return 0;
	}
	cout << MIN_distance;



	return 0;
}