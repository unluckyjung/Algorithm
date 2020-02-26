#if 00
#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int answer;

void solve(int sum){
    if(sum == n){
        answer++;
        return;
    }

    if(sum < n){
        for(int i = 1; i<=3; ++i){
            solve(sum + i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        answer = 0;
        cin >> n;
        solve(0);
        cout << answer <<"\n";
    }

    return 0;
}

#else

#include <bits/stdc++.h>

using namespace std;

int t;
int dp[11] = { 0,1,2,4 };

void solve() {
    for (int i = 4; i <= 10; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

void input() {
    cin >> t;

    solve();

    int num;
    while (t--) {
        cin >> num;
        cout << dp[num] << "\n";
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

#endif