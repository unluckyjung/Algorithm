#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000
using namespace std;

ll dp[MAX + 1][4];

int t;
const ll mod = 1000000009LL;


void init() {
    dp[1][1] = 1;
    dp[2][1] = 1;

    dp[2][2] = 1;

    dp[3][1] = 2;
    dp[3][2] = 1;
    dp[3][3] = 1;
}

void make_dp(const int &n, const int &m) {
    for (int k = 1; k <= 3; ++k) {
        dp[n][m] += dp[n - m][k];
    }
    dp[n][m] %= mod;
}

void solve() {
    init();
    for (int i = 4; i <= MAX; ++i) {
        for (int ii = 1; ii <= 3; ++ii) {
            make_dp(i, ii);
        }
    }

    int num;
    while (t--) {
        cin >> num;
        cout << (dp[num][1] + dp[num][2] + dp[num][3]) % mod << "\n";
    }
}

void input() {
    cin >> t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}