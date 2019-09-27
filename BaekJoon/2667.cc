#include <bits/stdc++.h>
using namespace std;

//2667 단지번호 붙이기.


vector<string> board;
bool visit[26][26];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int n;

queue<pair<int, int>>q;
vector<int> result;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string row;
		cin >> row;
		board.push_back(row);
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			int cnt = 0;
			if (board[i][ii] == '0' or visit[i][ii] == true) continue;
			visit[i][ii] = true; q.push({ i,ii }); cnt++;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
					if (board[nx][ny] == '0' or visit[nx][ny] == true) continue;
					visit[nx][ny] = true; q.push({ nx,ny }); cnt++;
				}
			}
			if (cnt != 0) result.push_back(cnt);
		}
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (auto it : result) cout << it << "\n";
	return 0;
}