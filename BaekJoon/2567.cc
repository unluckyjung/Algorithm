#include <bits/stdc++.h>
#define MAX 101
using namespace std;
bool board[MAX][MAX];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, answer;

void check(int i, int ii) {
	if (board[i][ii])return;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = i + dir[dx];
		int ny = ii + dir[dy];
		if (nx < 0 or nx >= MAX or ny < 0 or ny >= MAX)continue;
		if (!board[nx][ny])continue;
		answer++;
	}
}

void solve() {
	for (int i = 0; i < MAX; ++i) {
		for (int ii = 0; ii < MAX; ++ii) {
			check(i, ii);
		}
	}
}

void paper_set(int nx, int ny) {
	for (int i = nx; i < nx + 10; ++i) {
		for (int ii = ny; ii < ny + 10; ++ii) {
			if (board[i][ii])continue;
			board[i][ii] = true;
		}
	}
}

void input() {
	cin >> n;

	int nx, ny;
	while (n--) {
		cin >> ny >> nx;
		paper_set(nx, ny);
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
	cout << answer;

	return 0;
}