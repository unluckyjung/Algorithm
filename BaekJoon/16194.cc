#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001];

int solve() {
    for (int i = 2; i <= n; ++i) {
        for (int ii = 0; ii < i; ++ii) {
            int tmp = i - ii;
            dp[i] = min(dp[i], dp[tmp] * (i / tmp) + dp[i % tmp]);
        }
    }
    return dp[n];
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i)   cin >> dp[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    cout << solve();
    return 0;
}