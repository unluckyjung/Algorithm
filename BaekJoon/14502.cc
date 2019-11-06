#include<iostream>
#include<queue>
#include<cstring>

//boj.kr/14502
//백준 14502 연구소

using namespace std;

int board[8][8];
int visit[8][8];

int n, m;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int MAX = 0;

int virus_num;
int safe_count;

pair<int, int> virus[64];


void bfs() {

	int safe_count_tmp = safe_count - 3;
	queue<pair<int, int>> q;
	
	for (int i = 0; i < virus_num; ++i) {
		q.push({ virus[i].first, virus[i].second });
		visit[virus[i].first][virus[i].second] = true;
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (board[nx][ny] != 0)continue;
			if (visit[nx][ny])continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
			safe_count_tmp--;
		}
	}

	MAX = max(MAX, safe_count_tmp);
}

void dfs(int x, int y, int cnt) {

	if (cnt == 3) {
		memset(visit, false, sizeof(visit));
		bfs();	return;
	}

	for (int i = x; i < n; ++i) {
		for (int ii = y; ii < m; ++ii) {
			if (board[i][ii] == 0) {
				board[i][ii] = 1;
				dfs(i, ii, cnt+1);
				board[i][ii] = 0;
			}
		}
		y = 0;	//y는 0부터 탐색시켜야함.
		//실수할 수 있는여지.
		//왜냐면 y의 탐색이 다 끝난뒤에 x는 해당수의 다음수부터 탐색하지만 y는 그렇지 못하다.
		//(2,3)이 들어왔다고 가정시, 세로축 탐색이 끝나면, 
		//초기화를 안하면 (3,0)이아닌 (3,3)부터 탐색하게 된다.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	safe_count = n * m;

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
			if (board[i][ii] != 0) safe_count--;
			if (board[i][ii] == 2) {
				virus[virus_num].first = i;
				virus[virus_num].second = ii;
				virus_num++;
			}
		}
	}

	dfs(0, 0, 0);

	cout << MAX;
	return 0;
}