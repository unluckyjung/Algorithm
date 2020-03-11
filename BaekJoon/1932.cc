#include <bits/stdc++.h>
using namespace std;

int tree[501][501];
int dp[501][501];

int N;


int get_answer() {
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        answer = max(answer, dp[N][i]);
    }
    return answer;
}

void solve() {
    for (int n = 2; n <= N; ++n) {
        for (int m = 1; m <= n; ++m) {
            dp[n][m] = tree[n][m] + max(dp[n - 1][m - 1], dp[n - 1][m]);
        }
    }
    cout << get_answer() << "\n";
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int ii = 1; ii <= i; ++ii) {
            cin >> tree[i][ii];
        }
    }
    dp[1][1] = tree[1][1];
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