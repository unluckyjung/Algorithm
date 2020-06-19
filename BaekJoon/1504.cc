#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;

const int INF = INT_MAX;
vector<pii> node[802];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int cost[802];

int n, m;
int v1, v2;

void Reset() {
    for (int i = 1; i <= n; ++i) {
        cost[i] = INF;
    }
}

ll Dijstra(int st, int fin) {
    Reset();
    pq.push({ 0,st });
    cost[st] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();

        int cur_cost = cur.first;
        int cur_spot = cur.second;
        if (cost[cur_spot] != cur_cost) continue;

        for (const auto &nxt : node[cur_spot]) {
            int nxt_cost = cur_cost + nxt.first;
            int nxt_spot = nxt.second;

            if (nxt_cost < cost[nxt_spot]) {
                cost[nxt_spot] = nxt_cost;
                pq.push({ nxt_cost, nxt_spot });
            }
        }
    }
    return (ll)cost[fin];
}

ll Visit_v1_First() {
    return Dijstra(1, v1) + Dijstra(v1, v2) + Dijstra(v2, n);
}

ll Visit_v2_First() {
    return Dijstra(1, v2) + Dijstra(v2, v1) + Dijstra(v1, n);
}

void Solve() {
    ll route1 = Visit_v1_First();
    ll route2 = Visit_v2_First();

    if (route1 >= INF and route2 >= INF) {
        cout << -1 << "\n";
    }
    else cout << min(route1, route2) << "\n";
}


void Input() {
    cin >> n >> m;

    int a, b, _cost;
    while (m--) {
        cin >> a >> b >> _cost;
        node[a].push_back({ _cost, b });
        node[b].push_back({ _cost, a });
    }
    cin >> v1 >> v2;
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