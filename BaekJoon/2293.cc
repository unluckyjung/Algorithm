#include <bits/stdc++.h>
using namespace std;

vector<int>coin;
int dp[10002] = { 1 };

int n, k;

void solve() {
    for (int coin_val : coin) {
        for (int sum = coin_val; sum <= k; ++sum){
            dp[sum] += dp[sum - coin_val];
        }
    }
    cout << dp[k] << "\n";
}

void input() {
    cin >> n >> k;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        coin.push_back(num);
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