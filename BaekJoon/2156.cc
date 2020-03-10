#include <bits/stdc++.h>
using namespace std;

int dp[10001][3];
int alcol[10001];

int N, answer;

void solve() {
    for (int n = 2; n <= N; ++n) {
        dp[n][0] = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
        dp[n][1] = dp[n - 1][0] + alcol[n];
        dp[n][2] = dp[n - 1][1] + alcol[n];
    }
    cout << max({ dp[N][0], dp[N][1], dp[N][2] }) << "\n";
}

void input(){
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> alcol[i];
    }
    dp[1][1] = alcol[1];
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