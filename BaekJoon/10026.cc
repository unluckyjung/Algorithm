#include <bits/stdc++.h>
using namespace std;

//10026 적록색약

vector<string> board;
bool visit[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>>q;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		board.push_back(str);
	}

	int cnt = 2;
	while (cnt--) {

		if (cnt == 0) {
			//두번째 돌때는 색맹 세팅을 해준다.
			memset(visit, false, sizeof(visit));
			for (int i = 0; i < n; ++i)
				for (int ii = 0; ii < n; ++ii)
					if (board[i][ii] == 'R') board[i][ii] = 'G';
					//R을 전부 G로 바꿔준다.
		}

		int section = 0;

		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < n; ++ii) {
				if (visit[i][ii] == true)continue;
				visit[i][ii] = true;	q.push({ i,ii });
				section++;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();

					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
						if (visit[nx][ny] == true) continue;
						if (board[nx][ny] != board[cur.first][cur.second]) continue;
						//가려는곳의 색이, 지금 있는곳의 색과 다르면 넘어간다.
						visit[nx][ny] = true; q.push({ nx,ny });
					}

				}
			}
		}
		cout << section << " ";
	}

	return 0;
}