#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

vector<int> node[3002];
int answer[3002];
bool incycle[3002];
bool visit[3002];
int n;

queue<int> q;

void print_answer() {
    for (int i = 1; i <= n; ++i)
        cout << answer[i] << " ";
}

void bfs() {
    while (!q.empty()) {
        auto cur = q.front();   q.pop();

        for (auto nxt : node[cur]) {
            if (visit[nxt])continue;
            if (!incycle[nxt]) answer[nxt] = answer[cur] + 1;

            visit[nxt] = true;
            q.push(nxt);
        }
    }
}

//TODO : 가지치기
int dfs(int cur, int before) {
    for (auto nxt : node[cur]) {
        if (nxt == before) continue;
        if (visit[nxt]) {
            incycle[nxt] = true;
            incycle[cur] = true;
            return nxt;
        }
        visit[nxt] = true;
        int tmp = dfs(nxt, cur);
        if (tmp == cur or tmp == -1) return -1;
        if (tmp == -2) continue;
        incycle[cur] = true;
        return tmp;
    }
    return -2;
}

void solve() {
    visit[1] = true;
    dfs(1, 0);
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (!incycle[i])continue;
        answer[i] = 0;
        q.push(i);
    }
    bfs();
    print_answer();
}

void input() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
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