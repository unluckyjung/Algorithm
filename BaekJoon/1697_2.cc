#include <bits/stdc++.h>
using namespace std;

//1697 숨바꼭질

int board[100003];

int n, k;

int min = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(board, -1, sizeof(board));
	//전부다 -1로 초기화.
	cin >> n >> k;

	queue<int> q;
	board[n] = 0;
	//시작점은 0초로 시작.
	q.push(n);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == k) {
			//동생의 위치를 찾았으면 종료.
			cout << board[cur];
			return 0;
		}

		//계산식이 적혀있는 배열을 만든다.
		int arr[] = { cur - 1, cur + 1,cur * 2 };

		for (int i = 0; i < 3; ++i) {
			int nx = arr[i];
			if (nx < 0 or nx > 100000) continue;
			//런타임 에러 조심. 
			//음수가 board[]의 인덱스로 들어가지 않도록 조심.
			if (board[nx] != -1) continue;
			board[nx] = board[cur] + 1;
			q.push(nx);
		}
	}

	return 0;
}