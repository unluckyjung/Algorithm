#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int n, mod = 10007;

int solve(int n) {
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    return dp[n];
}

void input() {
    dp[0] = 1;
    dp[1] = 1;
    cin >> n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    cout << solve(n);
    return 0;
}