#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[4][100001];
ll sticker[4][100001];

int t, N;

void solve() {
	ll answer = 0;
	for (int n = 2; n <= N; ++n) {
		dp[0][n] = max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] });
		dp[1][n] = sticker[1][n] + max(dp[0][n - 1], dp[2][n - 1]);
		dp[2][n] = sticker[2][n] + max(dp[0][n - 1], dp[1][n - 1]);
	}
	cout << max({ dp[0][N], dp[1][N], dp[2][N] }) << "\n";
}

void init() {
	memset(dp, 0LL, sizeof(dp));
	dp[1][1] = sticker[1][1];
	dp[2][1] = sticker[2][1];
}


void input() {
	cin >> t;

	while (t--) {
		cin >> N;
		for (int line = 1; line <= 2; ++line) {
			for (int i = 1; i <= N; ++i) {
				cin >> sticker[line][i];
			}
		}
		init();
		solve();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();

	return 0;
}