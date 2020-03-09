#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1000000000LL;
int N, K;

ll dp[201][201];

void init() {
    for (int i = 0; i <= 200; ++i) {
        dp[0][i] = 1;
    }
}

void make_dp(int n, int k) {
    for (int m = 0; m <= n; ++m) {
        dp[n][k] += dp[n - m][k - 1] % mod;
    }
    dp[n][k] %= mod;
}

void solve() {
    for (int i = 1; i <= K; ++i) {
        for (int ii = 1; ii <= N; ++ii) {
            make_dp(ii, i);
        }
    }
    cout << dp[N][K] << "\n";
}

void input() {
    cin >> N >> K;
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