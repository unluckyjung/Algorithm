#include <bits/stdc++.h>
using namespace std;
//백준 3085 사탕게임
//https://www.acmicpc.net/problem/3085


char board[51][51];
int n;

int MAX = 1;

int dx[] = { 1,0 };
int dy[] = { 0,1 };


//위쪽이나 우측에 다른게 있나 확인한다.

//있다면 교체한다. 그리고 가장 길게 연결된 사탕을 찾는다.
//모든 좌표를 확인한다.
//위쪽이나 우측에 같은게 있는지 확인한다.
//있다면 있다면 해당 좌표로 이동.

//바꾼 좌표를 원위치 시킨다.

void right_find(int x, int y , int cnt) {
	if (board[x][y] == board[x + 1][y]) right_find(x + 1, y, cnt + 1);
	//현재 좌표와 우측 좌표가 같다면 cnt를 증가시키고 재귀탐색
	else MAX = max(MAX, cnt);
	return;
}

void up_find(int x, int y, int cnt) {
	if (board[x][y] == board[x][y+1]) up_find(x, y+1, cnt + 1);
	else MAX = max(MAX, cnt);
	return;
}

void find_max() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			if (board[i][ii] == board[i + 1][ii]) right_find(i, ii, 1);
			//현재 좌표와 우측이 같다면, 우측을 탐색.
			if (board[i][ii] == board[i][ii+1]) up_find(i, ii, 1);
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int ii = 0; ii < n; ++ii)
			cin >> board[i][ii];


	find_max();

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			for (int dir = 0; dir < 2; ++dir) {
				int nx = i + dx[dir];
				int ny = ii + dy[dir];

				if (nx >= n or ny >= n)continue;
				//처음에 이 조건을 안넣어줘서 잘못된 값이 나옴.

				if (board[i][ii] != board[nx][ny]) {
					//좌측이나 우측에 다른게 있었다면?
					swap(board[i][ii], board[nx][ny]);
					//위치를 바꾸고
					find_max();
					//가장 길게 연결된 사탕이 몇개인지 찾는다.
					swap(board[i][ii], board[nx][ny]);
				}
			}
		}
	}

	cout << MAX;
	return 0;
}