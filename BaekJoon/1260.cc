#include <bits/stdc++.h>
using namespace std;

vector<int> node[1002];
int visit[1002];
int n, m, s;

queue<int> q;
void bfs() {
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";

        for (auto it : node[cur]) {
            if (visit[it])continue;
            visit[it] = true;
            q.push(it);
        }
    }
}

void dfs(int cur) {
    cout << cur << " ";
    for (auto it : node[cur]) {
        if (visit[it])continue;
        visit[it] = true;
        dfs(it);
    }
}

void solve() {
    visit[s] = true;
    dfs(s);
    cout << "\n";

    memset(visit, false, sizeof(visit));

    visit[s] = true;
    q.push(s);
    bfs();
    cout << "\n";
}

void input() {
    cin >> n >> m >> s;

    int u, v;
    while (m--) {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(node[i].begin(), node[i].end());
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