#include <bits/stdc++.h>
using namespace std;

int n, k, t;
int fin;

vector<int> node[1002];
int build_cost[1002], build_dp[1002], build_indegree[1002];


void Solve() {
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (build_indegree[i] == 0) {
            q.push(i);
            build_dp[i] = build_cost[i];
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (const auto& nxt : node[cur]) {
            build_dp[nxt] = max(build_dp[nxt], build_dp[cur] + build_cost[nxt]);
            build_indegree[nxt]--;
            if (build_indegree[nxt] == 0) q.push(nxt);
        }
    }
    cout << build_dp[fin] << "\n";
}

void Input_Build_Order() {
    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        node[a].push_back(b);
        build_indegree[b]++;
    }
}

void Input_Build_Cost(){
    for (int i = 1; i <= n; ++i) {
        cin >> build_cost[i];
    }
}

void Init() {
    memset(build_cost, 0, sizeof(build_cost));
    memset(build_indegree, 0, sizeof(build_indegree));
    memset(build_dp, 0, sizeof(build_dp));
    for (int i = 1; i <= n; ++i) {
        node[i].clear();
    }
}

void Input() {
    cin >> t;
    while (t--) {
        Init();
        cin >> n >> k;
        Input_Build_Cost();
        Input_Build_Order();
        cin >> fin;
        Solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();

    return 0;
}