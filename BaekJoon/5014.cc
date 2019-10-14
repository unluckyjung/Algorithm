#include <bits/stdc++.h>
using namespace std;
//백준 5014 스타트링크
//https://www.acmicpc.net/problem/5014

int h;
int from;
int to;
int up, down;


int building[1000002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> from >> to >> up >> down;

	memset(building, -1, sizeof(building));


	queue<int> q;
	//큐에 있는것은 현재위치.
	building[from] = 0; q.push(from);
	//현재 위치의 이동거리 값을 0으로 만들고,
	//큐에 현재 위치를 넣음.


	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		//cur은 현재위치.
		//이동 거리량이 아님.

		if (cur == to) {
			//현재 위치가 목적했던 곳이면 종료.
			cout << building[cur];
			return 0;
		}

		int arr[] = { cur + up, cur - down };
		//arr에다가, 갈곳을 기록해둠.

		for (int i = 0; i < 2; ++i) {
			int nx = arr[i];

			if (nx <= 0 or nx > h)continue;
			//1층부터 시작이고 h층까지 갈 수 있음.
			if (building[nx] != -1)continue;

			building[nx] = building[cur] + 1;	q.push(nx);
		}

	}

	cout << "use the stairs";
	return 0;
}