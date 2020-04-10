#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> node[20002];
int check[20002];
int V, E;

#if 0
bool answer_check() {
    for (int i = 1; i <= V; ++i) {
        for (auto connect : node[i]) {
            if (check[i] == check[connect]) return false;
        }
    }
    return true;
}

void dfs(int cur) {
    for (auto next : node[cur]) {
        if (check[next] != 0) continue;
        check[next] = check[cur] * -1;
        dfs(next);
    }
}

void solve() {  //TODO : 접근했는데, 이미 마킹이 되어있고, 같은거라면 가지치기 기능.
    for (int i = 1; i <= V; ++i) {
        if (check[i] != 0)continue;
        check[i] = 1;   // mistake 1 :마킹을 안하고 dfs를 해서 무한루프
        dfs(i);
    }
    if (answer_check()) cout << "YES\n";
    else cout << "NO\n";
}

#else

bool dfs(int cur) {
    for (auto next : node[cur]) {
        if (check[next] == 0) {
            check[next] = check[cur] * -1;
            if (!dfs(next)) return false;
        }
        else if (check[cur] == check[next])return false;    //접근 했을때, 이미 마킹이 되어있고 같은거라면 가지치기.
    }
    return true;
}

void solve() {
    for (int i = 1; i <= V; ++i) {
        if (check[i] != 0)continue;
        check[i] = 1;

        if (!dfs(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


#endif

void init() {
    for (int i = 1; i <= V; ++i) {
        node[i].clear();
        check[i] = 0;
    }

    int a, b;
    while (E--) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
}

void input() {
    cin >> t;
    while (t--) {
        cin >> V >> E;
        init();
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}