#include <bits/stdc++.h>
using namespace std;

vector<int> node[1002];
bool visit[1002];
int n, m;


void dfs(int k) {
    for (auto it : node[k]) {
        if (visit[it]) continue;
        visit[it] = true;
        dfs(it);
    }
}

int solve() {

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (visit[i])continue;
        ret++;
        visit[i] = true;
        dfs(i);
    }
    return ret;
}

void input() {
    cin >> n >> m;

    int u, v;
    while (m--) {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    cout << solve() << "\n";

    return 0;
}