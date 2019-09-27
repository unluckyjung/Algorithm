#include <bits/stdc++.h>
using namespace std;


//2583 영역구하기

int board[101][101];
bool visit[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int n, m, k;

queue<pair<int, int>>q;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	//M = 5, N = 7 이지만, 세로축 5 가로축 7 이라고 생각하고 입력받는 순서로 반대로함

	//좌표값 받고 색칠하는 방법 1.

	//좌표값 받고 색칠하는 부분을 구현하는 이 부분에서 소요한 시간이 많음..
	//이 방법을 통해서는 원하는 그림과 동일하게 색칠하게 됨.
	//for (int i = 0; i < k; ++i) {
	//	pair<int, int>X;
	//	pair<int, int>Y;

	//	cin >> X.first >> X.second;
	//	cin >> Y.first >> Y.second;

	//	X.second = n - X.second;
	//	Y.second = n - Y.second;

	//	for (int ii = min(X.second, Y.second); ii < max(X.second, Y.second); ++ii) {
	//		for (int iii = min(X.first, Y.first); iii < max(X.first, Y.first); ++iii) {
	//			if (board[ii][iii] == 1) continue;
	//			board[ii][iii] = 1;
	//		}
	//	}
	//}

	
	//좌표값 받고 색칠하는 방법 2.

	int Fist_x, First_y, Second_x, Second_y;
	for (int i = 0; i < k; i++) {
		cin >> Fist_x >> First_y >> Second_x >> Second_y;
		//	(0,2) (4,4) 가 들어왔다고 가정해보자.
		for (int ii = First_y; ii <= Second_y - 1; ii++) {
			//첫번째 y좌표부터 두번째 y좌표 -1 까지 탐색한다.
			//y축 2 ~ 3칸을 칠한다는 이야기
			for (int iii = Fist_x; iii <= Second_x - 1; iii++) {
				//첫번째 x좌표부터부터 두번째 x좌표 -1 까지 탐색한다.
				//x축 0 ~ 3칸을 칠한단 이야기.
				board[ii][iii] = 1;
				//뒤집힌 상태로 칠해지지만, 어차피 구하려는 결과값에는 영향이 없다.
			}
		}
	}

	//그려진 그림 확인용.
	//for (int i = 0; i < n; ++i) {
	//	for (int ii = 0; ii < m; ++ii) {
	//		cout << board[i][ii] << ' ';
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			if (board[i][ii] == 1 or visit[i][ii] == true) continue;
			visit[i][ii] = true;	q.push({ i,ii });
			int pic_size = 1;
			//만약 처음 방문하는 빈공간일경우 크기를 1로 시작함.

			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
					if (board[nx][ny] == 1 or visit[nx][ny] == true)continue;
					visit[nx][ny] = true; q.push({ nx,ny });
					pic_size++;
				}
			}
			vec.push_back(pic_size);
			//큐가 비었을때 BFS가 끝난것이므로, 해당 빈공간 크기를 스택에 넣음.
		}
	}

	cout << vec.size() << "\n";
	sort(vec.begin(), vec.end());
	for (auto it : vec) cout << it << " ";

	return 0;

}