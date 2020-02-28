#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[91][2];
int n;

ll solve() {
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    return dp[n][1];
}

void input() {
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    cout << solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();

    return 0;
}
