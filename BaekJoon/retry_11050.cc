#include<bits/stdc++.h>
#include<regex>
using namespace std;

int dp[11][11];
int solve(const int &n, const int &r) {
	if (dp[n][r] != 0) return dp[n][r];
	if (r == 0 || n == r) return dp[n][r] = 1;

	return dp[n][r] = solve(n - 1, r - 1) + solve(n - 1, r);

	//if (n == r || r == 0)	return 1;
	//return solve(n - 1, r - 1) + solve(n - 1, r);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	cout << solve(n1, n2);

	return 0;
}