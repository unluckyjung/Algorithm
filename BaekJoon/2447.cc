#include<bits/stdc++.h>

using namespace std;

char board[3000][3000];

int n;


void print_answer() {
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < n; ++ii) {
			cout << board[i][ii];
		}
		cout << "\n";
	}
}

void solve(const int& k, const int &nx, const int &ny) {

	
	if (k == 1) {
		board[nx][ny] = '*';
		return;
	}

	else {
		int div = k / 3;
		for (int i = 0; i < 3; ++i) {
			for (int ii = 0; ii < 3; ++ii) {
				if (i == 1 && ii == 1)continue;
				solve(div, nx + i*div, ny + ii*div);
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(board, ' ', sizeof(board));

	cin >> n;

	solve(n, 0, 0);
	print_answer();

	return 0;
}