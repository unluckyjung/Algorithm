#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int MaSan, e, GunWoo;

int INF = INT_MAX;
int cost[5002];

vector<pii> node[5002];

void Init() {
    for (int i = 1; i <= MaSan; ++i) {
        cost[i] = INF;
    }
}

int Dijkstra(int st, int ed) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    Init();

    cost[st] = 0;
    pq.push({ 0,st });

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        int cur_cost = cur.first;
        int cur_spot = cur.second;

        if (cur_cost != cost[cur_spot]) continue;
        if (cur_spot == ed) return cur_cost;

        for (auto nxt : node[cur_spot]) {
            int nxt_cost = cur_cost + nxt.first;
            int nxt_spot = nxt.second;

            if (nxt_cost < cost[nxt_spot]) {
                cost[nxt_spot] = nxt_cost;
                pq.push({ nxt_cost, nxt_spot });
            }
        }
    }
    return -1;
}


int Visit_GunWoo() {
    int GunWoo_cost1 = Dijkstra(1, GunWoo);
    if (GunWoo_cost1 == -1) return -1;
    
    int GunWoo_cost2 = Dijkstra(GunWoo, MaSan);
    if (GunWoo_cost2 == -1) return -1;

    return GunWoo_cost1 + GunWoo_cost2;
}

int Go_MaSan() {
    return Dijkstra(1, MaSan);
}

void Solve() {
    //cout << Visit_GunWoo() << "\n" << Go_MaSan() << "\n";
    if (Visit_GunWoo() == Go_MaSan()) cout << "SAVE HIM\n";
    else cout << "GOOD BYE\n";
}

void Input() {
    cin >> MaSan >> e >> GunWoo;

    int a, b, _cost;
    for (int i = 0; i < e; ++i) {
        cin >> a >> b >> _cost;
        node[a].push_back({ _cost, b });
        node[b].push_back({ _cost, a });
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