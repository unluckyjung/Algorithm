#include <bits/stdc++.h>
using namespace std;
bool board[101][101];
int n;
int answer;

void solve(int nx, int ny) {
	for (int i = nx; i < nx + 10; ++i) {
		for (int ii = ny; ii < ny + 10; ++ii) {
			if (board[i][ii])continue;
			board[i][ii] = true;
			answer++;
		}
	}
}

void input() {
	cin >> n;

	int nx, ny;
	while (n--) {
		cin >> ny >> nx;
		solve(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	cout << answer;

	return 0;
}