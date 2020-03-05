#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[202][202] = { 1 };
const ll mod = 1000000000;
int n, k;


void solve() {
    for (int i = 1; i <= k; ++i) {
        for (int ii = 0; ii <= n; ++ii) {
            
            for (int iii = 0; iii <= ii; ++iii) {
                dp[i][ii] += dp[i - 1][ii - iii] % mod;
                dp[i][ii] %= mod;
            }

        }
    }

    cout << dp[k][n] << "\n";
}

void input() {
    cin >> n >> k;
    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}