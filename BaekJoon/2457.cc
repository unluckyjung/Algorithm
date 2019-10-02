#include <bits/stdc++.h>
using namespace std;
//백준 5427 불
//https://www.acmicpc.net/problem/5427


int T;
int n, m;

vector<string> board;

int human_time[1002][1002];
int fire_time[1002][1002];
//문제 제대로 읽자. 범위가 1000이상이었다.
//이전에 300으로 해놓고 계속틀림.

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

queue<pair<int, int>> fire_q;

int human_x, human_y;

void Fire_bfs() {
	while (!fire_q.empty()) {
		auto cur = fire_q.front();	fire_q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
			if (board[nx][ny] == '*' or board[nx][ny] == '#')continue;
			if (fire_time[nx][ny] != -1)continue;
			fire_time[nx][ny] = fire_time[cur.first][cur.second] + 1;
			fire_q.push({ nx, ny });
		}
	}
}

void Human_bfs(int i, int ii) {
	queue<pair<int, int>> human_q;

	human_time[i][ii] = 0; human_q.push({ i,ii });

	while (!human_q.empty()) {
		auto cur = human_q.front(); human_q.pop();

		if (cur.first == 0 or cur.first == n - 1 or cur.second == 0 or cur.second == m - 1) {
			//벽의 끝에 닿으면 탈출성공.
			cout << human_time[cur.first][cur.second] + 1 << "\n";
			return;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			//if (nx < 0 or nx >= n or ny < 0 or ny >= m) {
			//	cout << human_time[cur.first][cur.second] + 1 << "\n";
			//	return;
			//}

			if (board[nx][ny] == '*' or board[nx][ny] == '#')continue;
			if (human_time[nx][ny] != -1)continue;

			if (fire_time[nx][ny] == -1) {
				//불이 벽에 둘러 쌓여 있다거나, 불이 없다거나 해서 여전히 -1 인경우. 
				//사람은 그곳으로 지나갈 수 있다.
				human_time[nx][ny] = human_time[cur.first][cur.second] + 1;
				human_q.push({ nx, ny });
				continue;
			}

			if (human_time[cur.first][cur.second] + 1 >= fire_time[nx][ny])continue;
			//불이 지나간시간이 -1이 아니고, 사람속도와 같거나 빠른경우 continue 

			human_time[nx][ny] = human_time[cur.first][cur.second] + 1;
			human_q.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE\n";
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;	board.push_back(str);
		}

		memset(fire_time, -1, sizeof(fire_time));
		memset(human_time, -1, sizeof(human_time));

		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < m; ++ii) {
				if (board[i][ii] == '*') {
					fire_time[i][ii] = 0;
					fire_q.push({ i,ii });
				}
				if (board[i][ii] == '@') {
					human_x = i;
					human_y = ii;
				}

			}
		}
		Fire_bfs();
		Human_bfs(human_x, human_y);
		board.clear();


		//cout << "\n\n";
		//for (int i = 0; i < n; ++i) {
		//	for (int ii = 0; ii < m; ++ii) {
		//		cout << fire_time[i][ii] << "\t";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n\n";
		//for (int i = 0; i < n; ++i) {
		//	for (int ii = 0; ii < m; ++ii) {
		//		cout << human_time[i][ii] << "\t";
		//	}
		//	cout << "\n";
		//}


	}
	return 0;
}