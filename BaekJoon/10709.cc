#include <bits/stdc++.h>
#define MAX 101
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

char board[MAX][MAX];
int cloud_time[MAX][MAX];

int n, m;
queue<pp> q;

void output() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii)	cout << cloud_time[i][ii] << " ";
		cout << "\n";
	}
}

void solve() {
	while (!q.empty()) {
		pp cur = q.front(); q.pop();
		int ny;
		int cloud_move = 1;
		while(1) {
			ny = cur.y + cloud_move++;
			if (ny >= m)break;
			if (board[cur.x][ny] != '.' or cloud_time[cur.x][ny] != -1)break;
			cloud_time[cur.x][ny] = cloud_time[cur.x][ny - 1] + 1;
		}
	}
}

void input() {
	cin >> n >> m;
	memset(cloud_time, -1, sizeof(cloud_time));
	string line;
	for (int i = 0; i < n; ++i) {
		cin >> line;
		for (int ii = 0; ii < m; ++ii) {
			board[i][ii] = line[ii];
			if (board[i][ii] != 'c')continue;
			cloud_time[i][ii] = 0;	
			q.push({ i,ii });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	solve();
	output();


	return 0;
}