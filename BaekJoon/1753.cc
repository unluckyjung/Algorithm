#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int INF = INT_MAX;
int n, m;
int st;

vector<pii> node[20002];
int cost[20002];

priority_queue<pii, vector<pii>, greater<pii> > pq;

void Print_Answer() {
    for (int i = 1; i <= n; ++i) {
        if (cost[i] == INF) cout << "INF\n";
        else cout << cost[i] << "\n";
    }
}

void Dijkstra() {
    pq.push({ 0, st });
    cost[st] = 0;
    
    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        int cur_cost = cur.first;
        int cur_spot = cur.second;

        if (cur_cost != cost[cur_spot]) continue;

        for (const auto nxt : node[cur_spot]) {
            int nxt_cost = cur_cost + nxt.first;
            int nxt_spot = nxt.second;

            if (nxt_cost < cost[nxt_spot]) {
                cost[nxt_spot] = nxt_cost;
                pq.push({ nxt_cost, nxt_spot });
            }
        }
    }
}


void Solve() {
    Dijkstra();
    Print_Answer();
}

void Init() {
    for (int i = 1; i <= n; ++i) {
        cost[i] = INF;
    }
}
void Input() {
    cin >> n >> m;
    cin >> st;

    Init();

    int u, v, _cost;
    while (m--) {
        cin >> u >> v >> _cost;
        node[u].push_back({ _cost,v });
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}