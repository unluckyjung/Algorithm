#include <bits/stdc++.h>
#define pii pair<int,int> 

using namespace std;

int n, m;
const int INF = INT_MAX;

vector<pii> node[1002];
int distFromStart[1002];
int beforePath[1002];

void findPath(int s, int e) {
    vector<int> path;
    int curNode = e;
    while (curNode != s) {
        path.push_back(curNode);
        curNode = beforePath[curNode];
    }
    path.push_back(s);
    cout << path.size() << "\n";
    
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
}

int dijkstra(int s, int e) {
    int cost = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distFromStart[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int curNode = cur.second;
        int curWeight = cur.first;

        if (distFromStart[curNode] != curWeight) continue;
        
        for (pii next : node[curNode]) {
            int nextNode = next.second;
            int nextWeight = curWeight + next.first;

            if (nextWeight < distFromStart[nextNode]) {
                distFromStart[nextNode] = nextWeight;
                pq.push({ nextWeight, nextNode });
                beforePath[nextNode] = curNode;
            }
        }
    }
    return distFromStart[e];
}

void solve() {
    int s, e;
    cin >> s >> e;
    cout << dijkstra(s, e) << "\n";
    findPath(s, e);
}

void graphInit() {
    cin >> n;
    cin >> m;
    while (m--) {
        int s, e, w;
        cin >> s >> e >> w;
        node[s].push_back({ w,e });
    }

    for (int i = 1; i <= n; ++i) {
        distFromStart[i] = INF;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    graphInit();
    solve();

    return 0;
}