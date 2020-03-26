#include <bits/stdc++.h>
using namespace std;

vector<int> human[2002];
bool visit[2002];
int n, m;
bool find_answer;

void dfs(int cur, int depth) {
    if (find_answer) return;

    if (depth == 4) {
        find_answer = true;
        return;
    }

    for (auto nxt : human[cur]) {
        if (visit[nxt])continue;
        visit[nxt] = true;
        dfs(nxt, depth + 1);
        visit[nxt] = false;

        if (find_answer) return;
    }
  
}

int solve() {
    for (int i = 0; i < n; ++i) {
        visit[i] = true;
        dfs(i, 0);
        visit[i] = false;
        if (find_answer) return 1;
    }
    return 0;
}

void input() {
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        human[a].push_back(b);
        human[b].push_back(a);
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