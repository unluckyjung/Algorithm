#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

double dp[MAX], answer;
int n;

void ouput() {
	cout << fixed;
	cout.precision(3);
	cout << answer;
}

void solve() {
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i], dp[i] * dp[i - 1]);
		answer = max(answer, dp[i]);
	}
	ouput();
}

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> dp[i];
		answer = max(answer, dp[i]);
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

	return 0;
}