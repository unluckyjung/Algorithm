#include <bits/stdc++.h>
using namespace std;

int ans[10];

int n, m;

void func(int s, int cnt) {

    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }


    for (int i = s; i <= n; ++i) {
        ans[cnt] = i;
        func(i, cnt + 1);
    }
}

void solve() {
    func(1, 0);
}

void input() {
    cin >> n >> m;
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