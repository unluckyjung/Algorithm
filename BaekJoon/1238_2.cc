#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

const int MAX_NODE_COUNT = 1001;
const int INF = INT_MAX;
int dist[MAX_NODE_COUNT];
int n, m, partyNode;

vector<pii> forwardNode[MAX_NODE_COUNT];
vector<pii> reverseNode[MAX_NODE_COUNT];

vector<int> dijkstra(vector<pii> node[MAX_NODE_COUNT]) {
    priority_queue < pii, vector<pii>, greater<pii> > pq;

    vector<int> dist(n + 1, INF);
    dist[partyNode] = 0;
    pq.push({ 0, partyNode });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int curCost = cur.first;
        int curNode = cur.second;

        if (dist[curNode] != curCost) continue;
        for (pii next : node[curNode]) {
            int nextCost = next.first + curCost;
            int nextNode = next.second;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }
    return dist;
}

void input() {
    cin >> n >> m >> partyNode;
    while (m--) {
        int s, e, cost;
        cin >> s >> e >> cost;
        forwardNode[s].push_back({cost, e});
        reverseNode[e].push_back({cost, s});
    }
}

void solve() {
    input();
    vector<int> fromPartyRoomDist = dijkstra(forwardNode);
    vector<int> toPartyRoomDist = dijkstra(reverseNode);

    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        answer = max(answer, fromPartyRoomDist[i] + toPartyRoomDist[i]);
    }
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    solve();

    return 0;
}