#include <bits/stdc++.h>
using namespace std;
//백준 13549 숨박꼭질 3
//https://www.acmicpc.net/problem/숨박꼭질 3

int board[100001];
int n, k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(board, -1, sizeof(board));
	cin >> n >> k;

	queue<int> q;
	board[n] = 0; q.push(n);
	//n은 현재위치 board[n]은 이동시간.
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur == k) {
			cout << board[cur];
			return 0;
		}
		int arr[] = { cur - 1, cur + 1, cur * 2 };
		for (int dir = 0; dir < 3; ++dir) {
			int nx = arr[dir];
			if (nx < 0 or nx > 100000)continue;


			//if(board[nx] != -1)continue; 로 하면 틀린다.

			//-1이 아닌 경우에 탐색시키는 경우,
			//순간이동은 0초 이동이기 때문에 걸어서 먼저 도착한 시간보다
			//다른곳을 갔다가 순간이동으로 오는 경우가 더 빠를 수 있다.

			if (dir == 2) {
				if (board[nx] != -1 and board[nx] > board[cur]) {
					//이전에 방문했지만 (-1이 아니지만)
					//순간이동으로 가는게 이전에 방문할때 걸린 시간보다 짧다면
					board[nx] = board[cur]; q.push(nx);
				}
				else if (board[nx] == -1) {
					//이전에 방문한 곳이 아니라면 (-1이라면)
					board[nx] = board[cur]; q.push(nx);
				}
			}
			else {
				if (board[nx] == -1) {
					board[nx] = board[cur] + 1; q.push(nx);
				}
			}
		}
	}

	return 0;
}