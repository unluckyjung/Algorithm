#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int INF = INT_MAX;
int n, st, ed;
int cost[1002];
vector<pii> node[1002];

void Init() {
    for (int i = 1; i <= n; ++i) {
        cost[i] = INF;
    }
}

int Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    Init();
    cost[st] = 0;
    pq.push({ 0, st });

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        int curCost = cur.first;
        int curSpot = cur.second;

        if (curCost != cost[curSpot]) continue;

        if (curSpot == ed) return curCost;

        for (auto nxt : node[curSpot]) {
            int nxtCost = curCost + nxt.first;
            int nxtSpot = nxt.second;

            if (nxtCost < cost[nxtSpot]) {
                cost[nxtSpot] = nxtCost;
                pq.push({ nxtCost, nxtSpot });
            }
        }
    }
    return -1;
}

void Solve() {
    cout << Dijkstra() << "\n";;
}

void Input() {
    int m;
    cin >> n >> m;

    int a, b, _cost;
    while (m--) {
        cin >> a >> b >> _cost;
        node[a].push_back({ _cost, b });
    }
    cin >> st >> ed;
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