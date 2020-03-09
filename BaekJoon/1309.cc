#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100002][3];
const ll mod = 9901LL;
int N;

void solve() {
    for (int n = 2; n <= N; ++n) {
		dp[n][0] = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % mod;
		dp[n][1] = (dp[n - 1][0] + dp[n - 1][2]) % mod;
		dp[n][2] = (dp[n - 1][0] + dp[n - 1][1]) % mod;
    }

    ll sum = 0;
    for (int i = 0; i <= 2; ++i) {
        sum += dp[N][i];
    }
    cout << sum % mod << "\n";
}

void input() {
    cin >> N;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
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