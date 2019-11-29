#include<bits/stdc++.h>

using namespace std;

long long dp[68] = { 1, 1, 2, 4 };
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 4; i < 69; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}


	return 0;
}