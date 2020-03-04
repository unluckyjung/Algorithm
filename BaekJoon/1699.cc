#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int n;

void solve() {
    for (int i = 2; i <= n; ++i) {
        dp[i] = INT_MAX;
        for (int ii = 1; ii * ii <= i; ++ii) {
            dp[i] = min(dp[i], 1 + dp[i - (ii * ii)]);
        }
    }
    cout << dp[n];
}

void input() {
    cin >> n;
    dp[1] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    //cout << (int)sqrt(142);

    return 0;
}