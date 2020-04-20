#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt;

int arr[22];

void dfs(int cur, int idx) {

	if (idx == n) return;
	if (cur + arr[idx] == s)  cnt++;

	dfs(cur + arr[idx], idx + 1);
    dfs(cur, idx + 1);
}

void solve() {
    dfs(0, 0);
    cout << cnt << "\n";
}

void input() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
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