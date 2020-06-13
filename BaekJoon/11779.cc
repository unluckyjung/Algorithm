#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int INF = INT_MAX;
int n, m;
int st, ed;

vector<pii> node[1002];
priority_queue<pii, vector<pii>, greater<pii> >pq;
int pre[1002], cost[1002];

void Get_Answer() {
    vector<int> path;
    int cur = ed;
    while(st != cur){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << cost[ed] << "\n";
    cout << path.size() << "\n";
    for (const auto it : path) {
        cout << it << " ";
    }
    cout << "\n";
}

void Dijstra() {
    pq.push({ 0,st });
    cost[st] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        int cur_cost = cur.first;
        int cur_idx = cur.second;

        if (cur_cost != cost[cur_idx]) continue;
        
        for (const auto &nxt : node[cur_idx]) {
            int nxt_cost = cur_cost + nxt.first;
            int nxt_idx = nxt.second;

            if (nxt_cost < cost[nxt_idx]) {
                cost[nxt_idx] = nxt_cost;
                pq.push({ nxt_cost, nxt_idx });
                pre[nxt_idx] = cur_idx;
            }

        }

    }
}


void Solve() {
    Dijstra();
    Get_Answer();
}

void Init() {
    for (int i = 1; i <= n; ++i) {
        cost[i] = INF;
    }
}

void Input() {
    cin >> n;
    cin >> m;
    Init();

    int _st, _ed, _cost;
    while (m--) {
        cin >> _st >> _ed >> _cost;
        node[_st].push_back({ _cost , _ed });
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