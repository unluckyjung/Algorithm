#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[1001][10];
int N;
const ll mod = 10007LL;


void make_dp(int n, int m) {
	for (int k = 0; k <= m; ++k) {
		dp[n][m] = (dp[n][m] + dp[n - 1][k]) % mod;
	}
}

void solve() {
	for (int n = 2; n <= N; ++n) {
		for (int m = 0; m <= 9; ++m) {
			make_dp(n, m);
		}
	}

	ll answer = 0;
	for (int i = 0; i <= 9; ++i) {
		answer = (answer + dp[N][i]) % mod;
	}
	cout << answer << "\n";
}


void init() {
	for (int i = 0; i <= 9; ++i) {
		dp[1][i] = 1;
	}
}


void input() {
	cin >> N;
	init();
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}