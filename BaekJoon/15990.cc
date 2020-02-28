#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;

int n;
const ll mod = 1000000009LL;
ll dp[MAX+1][4];

void calculate(int i, int ii) {
    for (int k = 1; k <= 3; ++k) {
        if (k == ii)continue;
        dp[i][ii] += dp[i-ii][k] % mod;
    }
    dp[i][ii] %= mod;
}

void solve() {
    for (int i = 4; i <= MAX; ++i) {
        for (int ii = 1; ii <= 3; ++ii) {
            calculate(i, ii);
        }
    }
}

void input() {
    dp[1][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    cin >> n;
    solve();
    
    int num;
    while (n--) {
        cin >> num;
        cout << (dp[num][1] + dp[num][2] + dp[num][3])%mod << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();

    return 0;
}