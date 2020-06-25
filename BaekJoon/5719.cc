#if 01

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int INF = INT_MAX;
int n, m, st, ed;
int cost[502];
int visitedCost[502][502];

vector<pii> node[502];

void VisitedMarking() {
    // 끝 지점부터, 
    // (시작점 -> 도착점의 비용) + (시작점까지의 최단비용) == (도착점까지의 최단 비용) 을 BFS를 통해 확인한다.
    queue<int> q;
    q.push(ed);

    while (!q.empty()) {
        int cur = q.front();    q.pop();

        for (int pre = 0; pre < n; ++pre) {
            if (visitedCost[pre][cur] == INF) continue;
            if (visitedCost[pre][cur] + cost[pre] != cost[cur]) continue;

            visitedCost[pre][cur] = INF;
            q.push(pre);
        }
    }
}

void CostReset() {
    for (int i = 0; i < n; ++i) {
        cost[i] = INF;
    }
}

int Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    CostReset();
    cost[st] = 0;
    pq.push({ 0, st });

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        int curCost = cur.first;
        int curSpot = cur.second;

        if (curCost != cost[curSpot]) continue;

        for (auto nxt : node[curSpot]) {
            int nxtCost = curCost + nxt.first;
            int nxtSpot = nxt.second;
            if (visitedCost[curSpot][nxtSpot] == INF) continue;

            if (nxtCost < cost[nxtSpot]) {
                cost[nxtSpot] = nxtCost;
                pq.push({ nxtCost, nxtSpot });
            }
        }
    }
    return cost[ed];
}

int Solve() {
    int minCost = Dijkstra();
    if (minCost == INF) return -1;
    VisitedMarking();

    while (1) {
        int secondCost = Dijkstra();
        if (secondCost == INF) return -1;    // 경로가 없거나, 모든 경로가 최단 경로인 경우.
        if (minCost != secondCost) return secondCost;
    }
    return -1;
}

void InputPath() {
    int a, b, _cost;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> _cost;
        node[a].push_back({ _cost,b });
        visitedCost[a][b] = _cost;
    }
}

void PathReset() {
    for (int i = 0; i < n; ++i) {
        node[i].clear();
        for (int ii = 0; ii < n; ++ii) {
            visitedCost[i][ii] = INF;
        }
    }
}

void Input() {
    while (1) {
        cin >> n >> m;
        if (n == 0 and m == 0) break;
        cin >> st >> ed;
        PathReset();
        InputPath();
        cout << Solve() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();

    return 0;
}



#else

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int INF = INT_MAX;
int n, m, st, ed;
int cost[502];
int node[502][502];

void VisitedMarking() {
    queue<int> q;
    q.push(ed);

    while (!q.empty()) {
        int cur = q.front();    q.pop();

        for (int pre = 0; pre < n; ++pre) {
            if (node[pre][cur] == INF) continue;
            if (node[pre][cur] + cost[pre] != cost[cur]) continue;

            node[pre][cur] = INF;
            q.push(pre);
        }
    }
}

void CostReset() {
    for (int i = 0; i < n; ++i) {
        cost[i] = INF;
    }
}

int Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    CostReset();
    cost[st] = 0;
    pq.push({ 0, st });

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        int curCost = cur.first;
        int curSpot = cur.second;

        if (curCost != cost[curSpot]) continue;

        for (int nxtSpot = 0; nxtSpot < n; ++nxtSpot) {
            if (node[curSpot][nxtSpot] == INF) continue;
            int nxtCost = curCost + node[curSpot][nxtSpot];

            if (nxtCost < cost[nxtSpot]) {
                cost[nxtSpot] = nxtCost;
                pq.push({ nxtCost, nxtSpot });
            }
        }
    }
    return cost[ed];
}

int Solve() {
    int minCost = Dijkstra();
    if (minCost == INF) return -1;
    VisitedMarking();

    while (1) {
        int secondCost = Dijkstra();
        if (secondCost == INF) return -1;
        if (minCost != secondCost) return secondCost;
    }
    return -1;
}

void InputPath() {
    int a, b, _cost;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> _cost;
        node[a][b] = _cost;
    }
}

void PathReset() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            node[i][ii] = INF;
        }
    }
}

void Input() {
    while (1) {
        cin >> n >> m;
        if (n == 0 and m == 0) break;
        cin >> st >> ed;
        PathReset();
        InputPath();
        cout << Solve() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();

    return 0;
}

#endif