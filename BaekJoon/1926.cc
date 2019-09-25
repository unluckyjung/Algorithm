#include<bits/stdc++.h>
using namespace std;

//1926 그림

int pic[502][502];	//그림 배열
bool visit[502][502];	//방문표시

//사방면을 탐색하기 위한 배열
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
int pic_max = 0;
int pic_num = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> pic[i][ii];
		}
	}

	//모든 공간을 일단 탐색해본다.
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			//[i][ii]에 대한 BFS

			//만약 이미 방문한곳이거나 , 그림이 아닌경우 continue
			if (visit[i][ii] or pic[i][ii] == 0) continue;

			//큐를 만든다.
			queue<pair<int, int>> q;
			//방문했다는 표시를 하고 q에 push한다.
			visit[i][ii] = true; q.push({ i,ii });

			//현재 그림의 크기를 잴 변수
			int curpic_size = 0;
			//처음 방문하는 그림이므로 그림의 수 증가.
			pic_num++;

			while (!q.empty()) {
				//큐가 빌떄까지 탐색한다.
				curpic_size++;
				//현재 그림의 크기를 증가시킴.
				auto curpic = q.front(); q.pop();
				// 큐의 front를 가르키고, 그것을 바로뺀다.

				//4방면 탐색시작.
				for (int dir = 0; dir < 4; ++dir) {
					int nx = curpic.first + dx[dir];
					int ny = curpic.second + dy[dir];

					//만약 방문했던곳이거나 그림의 일부분이 아니라면
					//만약 범위밖을 넘어설경우 continue 시킨다.
					if (visit[nx][ny] or pic[nx][ny] == 0)continue;
					if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
					
					//위의 경우에 해당하지 않는경우, 방문 표시를 하고 push한다.
					visit[nx][ny] = true; q.push({ nx,ny });
				}
			}
			//[i][ii]로부터 시작된 BFS가 끝났으면,
			//[i][ii]부터 시작된 그림의 크기가 제일큰지 확인한다.
			pic_max = max(pic_max, curpic_size);
		}
	}

	cout << pic_num << "\n" << pic_max;

	return 0;
}