#include <bits/stdc++.h>

using namespace std;

vector<int> node[102];
bool isVisited[102];

int computer_n, m;
int answer;

void dfs(int cur) {
    for (auto next : node[cur]) {
        if (isVisited[next]) continue;
        isVisited[next] = true;

        answer++;
        dfs(next);
    }
}

void solve() {
    isVisited[1] = true;
    dfs(1);
    cout << answer << "\n";
}

void input() {
    cin >> computer_n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}