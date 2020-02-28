#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[101][10];
int n;

const int mod = 1000000000LL;

ll solve() {
    for (int i = 2; i <= n; ++i) {
        for (int ii = 0; ii <= 9; ++ii) {
            if (ii - 1 >= 0) dp[i][ii] += dp[i - 1][ii - 1];
            if (ii + 1 <= 9) dp[i][ii] += dp[i - 1][ii + 1];
            dp[i][ii] %= mod;
        }
    }
    ll answer = 0;
    for (int i = 1; i <= 9; ++i) {
        answer = (answer + dp[n][i])%mod;
    }
    return answer % mod;
}

ll input() {
    cin >> n;
    if (n == 1) return 9;

    for (int i = 0; i <= 9; ++i) dp[1][i] = 1;
    return solve();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    cout << input();

    return 0;
}