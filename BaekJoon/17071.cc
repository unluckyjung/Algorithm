//#include<bits/stdc++.h>
//using namespace std;
//
//int board[500001];
//
//queue<int> q;
//int cnt;
//int n, k;
//
//int subin, sister;
//int day;
//
//
//void sister_move() {
//	day++;
//	k += day;
//	cout << k << " ";
//	if (k > 500000) {
//		cout << -1 << "\n";
//		exit(0);
//	}
//}
//
//void bfs() {
//	memset(board, -1, sizeof(board));
//	subin = n, sister = k;
//	board[subin] = 0;
//
//	q.push(subin);
//
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//		if (cur == sister && board[cur] == day) {
//			cout << board[cur] << "\n";
//			exit(0);
//		}
//
//		int arr[] = { cur + 1, cur - 1 ,cur * 2 };
//		for (int dir = 0; dir < 3; ++dir) {
//			int nx = arr[dir];
//			if (nx < 0 or nx >500000)continue;
//			if (board[nx] != -1)continue;
//			if (board[cur] + 1 > day)continue;
//			board[nx] = board[cur] + 1;
//			q.push(nx);
//		}
//	}
//
//	sister_move();
//	bfs();
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> k;
//	bfs();
//
//	return 0;
//}