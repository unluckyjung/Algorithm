#include<bits/stdc++.h>
using namespace std;

//	백준 2146 다리만들기
//	boj.kr/2146

int board[101][101];
int dx[4] = { -1, 1 , 0 , 0 };
int dy[4] = { 0, 0 , -1 , 1 };
int n;
int visit[101][101];
vector<pair<int, int>> land[10001];
//i번째 섬에 포함된 좌표들(pair<int,int>)

bool range_check(int a, int b) {
	return a < 0 or a >= n or b < 0 or b >= n;
}

int land_num = 1;

void land_bfs() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			if (visit[i][ii] or board[i][ii] == 0)continue;
			queue<pair<int, int>> q;
			visit[i][ii] = true; q.push({ i,ii });

			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				int curx = cur.first;
				int cury = cur.second;
				board[curx][cury] = land_num;
				land[land_num].push_back({ curx,cury });

				for (int dir = 0; dir < 4; ++dir) {
					int nx = curx + dx[dir];
					int ny = cury + dy[dir];
					if (range_check(nx, ny) or visit[nx][ny] or board[nx][ny] == 0) continue;
					visit[nx][ny] = true; q.push({ nx,ny });
				}
			}
			land_num++;
		}
	}

	return;
}

int bridge_bfs(int idx) {
	queue<pair<pair<int, int>, int> > q;
	for (auto e : land[idx]) {
		q.push({ {e.first,e.second }, 0 });
		//여기서 0은 다리 초기 길이.

		visit[e.first][e.second] = idx;
		//visit 배열에다가 해당 섬의 번호를 넣는다.
		//이것은 나중에 방문하는곳이 이섬부터 탐색한곳인지 확인하는데 쓰임.
		//다시말하면 몇번섬으로부터 만들어진 다리인지를 확인하는데 쓰임.
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cx = cur.first.first;
		int cy = cur.first.second;
		int distance = cur.second;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (range_check(nx,ny) or visit[nx][ny] == idx) continue;	//이전에 방문한곳인가?
			if (board[nx][ny] == idx)continue;	//같은 섬인가?
			if (board[nx][ny] != 0) return distance;	//같은 섬이 아니고, 바다가 아니라는건 다른섬.

			visit[nx][ny] = idx;	//바다인 경우 해당위치에 해당섬으로부터 뻗어나가는 다리를 만듬
			q.push({ { nx,ny },distance + 1 });
		}
	}
	return 123123;
	//다른섬을 만나지 못한경우, 엄청나게 큰값 반환.
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cin >> board[i][ii];
		}
	}

	land_bfs();

	int ans = INT_MAX;
	for (int i = 1; i < 10000; ++i) {
		if (land[i].empty())break;
		ans = min(ans, bridge_bfs(i));
	}
	cout << ans;
	return 0;
}