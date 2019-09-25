#include<bits/stdc++.h>
using namespace std;

//2178 미로탐색

int board[102][102];
int dist[102][102];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int ii = 0; ii < m; ++ii) {
			board[i][ii] = str[ii] - '0';
			//문자이기 때문에 정수화 시켜서 넣어줌.
		}
	}

	queue<pair<int, int>> q;
	dist[0][0]++; q.push({ 0,0 });
	//시작점 1로 만들고 큐에 넣음.

	while (!q.empty()) {
		auto cur = q.front();	q.pop();
		
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (board[nx][ny] == 0 or dist[nx][ny] != 0) continue;
			//dist가 0이 아닌경우는 방문했다는것을 의미.

			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;

			//이부분에서 고민좀함.
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			//현재 위치에서 +1 한 만큼을 넣으면 다음 거리.
			//큐에 원소들이 한번만 들어간다는게 보장되기 때문.
			q.push({ nx,ny });
		}
	}

	//인텔리 센스에서 0이 들어올경우에 에러가 나기 때문에 경고 표시를 해준다.
	//어차피 n과 m이 2 이상이 들어온다고 했기 때문에 상관X
	cout << dist[n-1][m-1];

	return 0;
}