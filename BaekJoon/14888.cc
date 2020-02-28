#include <bits/stdc++.h>
using namespace std;

int arr[12], oper[4];
int n;
int MAX = INT_MIN, MIN = INT_MAX;

#if 01
void dfs(int cur, int cnt) {

    if (cnt == n) {
        MAX = max(MAX, cur);
        MIN = min(MIN, cur);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (oper[i]) {
            oper[i]--;
            if(i == 0) dfs(cur + arr[cnt], cnt + 1);
            else if (i == 1) dfs(cur - arr[cnt], cnt + 1);
            else if (i == 2) dfs(cur * arr[cnt], cnt + 1);
            else if (i == 3) dfs(cur / arr[cnt], cnt + 1);
            oper[i]++;
        }
    }
}

#else
void dfs(int cur, int cnt) {

    if (cnt == n) {
        MAX = max(MAX, cur);
        MIN = min(MIN, cur);
        return;
    }

    int tmp = cur;

    if (oper[0]) {
        oper[0]--;
        dfs(cur + arr[cnt], cnt + 1);
        oper[0]++;
    }

    if (oper[1]) {
        oper[1]--;
        dfs(cur - arr[cnt], cnt + 1);
        oper[1]++;
    }

    if (oper[2]) {
        oper[2]--;
        dfs(cur * arr[cnt], cnt + 1);
        oper[2]++;
    }

    if (oper[3]) {
        oper[3]--;
        dfs(cur / arr[cnt], cnt + 1);
        oper[3]++;
    }
}

#endif
void solve() {
    dfs(arr[0], 1);
    cout << MAX << "\n" << MIN << "\n";
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i)   cin >> arr[i];
    for (int i = 0; i < 4; ++i)   cin >> oper[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);
    input();
    solve();
    return 0;
}