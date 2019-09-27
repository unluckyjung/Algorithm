#include<bits/stdc++.h>
using namespace std;

//2206 벽부시고 이동하기

vector<string> board;
int dist[1001][1001][2];	
//3차원 배열로 스킬 사용 여부도 확인한다.

int n, m;
int MIN_distance = INT_MAX;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(void) {

	queue<pair<pair<int, int>, int>>q;
	dist[0][0][1] = 0;	q.push({ { 0,0 }, 1 });
	//스킬을 1번 사용할 수 있다고 표시하고, 시작위치를 큐에넣는다.

	while (!q.empty()) {
		auto cur = q.front();	q.pop();
		auto x = cur.first.first;
		auto y = cur.first.second;
		auto skill = cur.second;

		if (x == n - 1 and y == m - 1) {
			//목적지 도달시 출력후 종료.
			MIN_distance = dist[x][y][skill];
			return;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;

			if (dist[nx][ny][skill] != -1)continue;
			//방문한곳이면 건너뛴다.


			//문제 해결의 핵심부분.
			if (board[nx][ny] == '1') {
				//벽이 막혀있을때
				if (skill) {
					//스킬을 1회 쓸 수 있다면 큐에 넣을 수 있다. (벽을 부시고)
					dist[nx][ny][skill - 1] = dist[x][y][skill] + 1;
					//스킬을 사용했기때문에 skill -1 을한다.
					//dist[nx][ny][0]에 지금까지 이동한거리 + 1을 넣는다.
					//dist[nx][ny][1]은 이제 필요없는곳이다.
					//왔던길로 돌아갈 순 있지만 ex ) dist[1][1][1] = 2 but dist[1][1][0] = -1
					//어차피 왔던곳으로 돌아가도, 목적지에 도달할 순 없으니 상관없다.

					q.push({ { nx,ny },skill - 1 });
					//[nx][ny][0]을 큐에 넣는다. 0이기 때문에 이제는 스킬을 쓸 수 없게된다.
				}
			}
			else {
				//이전에는 else를 넣지 않아서 원하는 결과값을 내지 못했다.
				//else가 없으면 위에서 큐를 넣고 아래서도 큐를 넣어버리기 때문에 문제가 생긴다.
				dist[nx][ny][skill] = dist[x][y][skill] + 1;
				//가려는 좌표에 현재값 + 1을 넣어준다.
				q.push({ { nx,ny },skill});
				//큐에 넣는다.
			}
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

	if (MIN_distance == INT_MAX) {
		cout << -1;	return 0;
	}
	cout << MIN_distance +1 ;
	//시작하는 칸도 포함해서 세기 떄문에 +1 해준다.


	return 0;
}