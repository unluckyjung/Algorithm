#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];

int N;

int find_max(int n) {
    int tmp = 0;
    for (int m = 1; m <= n; ++m) {
        if (arr[m] >= arr[n])continue;
        tmp = max(tmp, dp[m]);
    }
    return tmp;
}

void solve() {
    int answer = 0;
    for (int n = 1; n <= N; ++n) {
        dp[n] = arr[n] + find_max(n);
        answer = max(answer, dp[n]);
    }
    cout << answer << "\n";
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
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