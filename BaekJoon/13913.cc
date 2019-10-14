#include <bits/stdc++.h>
using namespace std;
//백준 13913 숨바꼭질 4
//https://www.acmicpc.net/problem/13913

int board[100001];
int parent[100001];
int n, k;

vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(board, -1, sizeof(board));
	memset(parent, -1, sizeof(parent));

	cin >> n >> k;

	queue<int> q;
	board[n] = 0; q.push(n);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur == k) {
			cout << board[cur] << "\n";

			int index = cur;
			ans.push_back(index);

			//break 위치를 신경쓰자.

			//만약 2에서 출발하고 2가 목적지인경우.
			//2는 -1에서 왔다고 적혀있음. (parent[2] = -1)
			//이때 index 는 -1이 되어버리고
			//parent[-1]에 접근하기 때문에 문제가 생김.

			while (1) {
				if (index == n) break;
				index = parent[index];
				ans.push_back(index);
			}


			for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
				cout << *it << " ";
			}
			return 0;
		}
		int arr[] = { cur + 1,cur - 1,cur * 2 };
		for (int i = 0; i < 3; ++i) {
			int nx = arr[i];
			if (nx < 0 or nx > 100000)continue;
			if (board[nx] != -1)continue;
			board[nx] = board[cur] + 1;	q.push(nx);
			if(parent[nx] == -1) parent[nx] = cur;
			//-1이 아닌경우에 다 접근할시 메모리 초과.
		}
	}


	return 0;
}