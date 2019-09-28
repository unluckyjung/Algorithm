#include<bits/stdc++.h>
using namespace std;
//2468 안전영역
//https://www.acmicpc.net/problem/2468

int n;

int board[101][101];
bool visit[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int MAX = 1;
//비가 한방울도 오지않는경우 모든 건물이 잠기지 않는다.
//즉 모든 건물이 잠기지 않았으므로 최소 1개의 지점이 최소값이다.

queue<pair<int, int>>q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cin >> board[i][ii];
		}
	}

	for (int rain = 0; rain <= 100; ++rain) {
		//문제 똑바로 읽기. 비가 어느정도 오는 경우의 수가 존재하고,
		//비가 적게왔지만, 잠기지 않은 "지점"이 더 적을 수 있다.
		//반대로 비가 많이 왔지만, 잠기지 않은 "지점"이 더 많을 수 있다.
		//비가 0 ~ 100까지 온다.

		int area = 0;
		//처음에 잠기지 않은 지점의 수는 0개로 시작한다.

		memset(visit, false, sizeof(visit));
		//비가 오는 경우의수가 달라질경우 visit를 초기화 해주어야한다.

		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < n; ++ii) {
				if (board[i][ii] <= rain or visit[i][ii]) continue;
				visit[i][ii] = true;	q.push({ i,ii });
				area++;
				//새로운 지점을 발견했을때 area ++ 해준다.

				while (!q.empty()) {
					//이걸왜 if로 적었었지?? while이다.

					auto cur = q.front();	q.pop();

					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
						if (visit[nx][ny] or board[nx][ny] <= rain)continue;
						visit[nx][ny] = true;	q.push({ nx,ny });
					}
				}
			}
		}
		MAX = max(MAX, area);
		//비가 온 경우의 수에 맞춰서 가장 잠기지 않은 지점이 많은 경우를 저장한다.
	}
	cout << MAX;

	return 0;
}