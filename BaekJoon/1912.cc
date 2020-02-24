#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int dp[MAX];
int n;

int solve() {
    int answer = dp[0];
    
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        answer = max(answer, dp[i]);
    }
    return answer;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i)   cin >> dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    cout << solve();
    return 0;
}