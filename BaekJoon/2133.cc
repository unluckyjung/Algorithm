#include <bits/stdc++.h>
using namespace std;

int dp[32];
int N;

void solve() {
    for (int n = 2; n <= N; ++n) {
        dp[n] = dp[n - 2] * 3;
        for (int m = 2; m <= n / 2; ++m) {
            dp[n] += dp[n - 2 * m] * 2;
        }
    }
    cout << dp[N] << "\n";
}

void input() {
    cin >> N;
    dp[0] = 1;
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