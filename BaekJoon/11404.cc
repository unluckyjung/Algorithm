#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 + 2;
int cost[102][102];
int n;

void Print_Answer() {
    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= n; ++ii) {
            if (cost[i][ii] == INF) cout << 0 << " ";
            else cout << cost[i][ii] << " ";
        }
        cout << "\n";
    }
}

void Solve() {
    for (int visit = 1; visit <= n; ++visit) {
        for (int s = 1; s <= n; ++s) {
            for (int e = 1; e <= n; ++e) {
                cost[s][e] = min(cost[s][e], cost[s][visit] + cost[visit][e]);
            }
        }
    }
    Print_Answer();
}

void Init() {
    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= n; ++ii) {
            if (i == ii) continue;
            cost[i][ii] = INF;
        }
    }
}

void Input(){
    cin >> n;

    Init();

    int m;
    cin >> m;
    while (m--) {
        int a, b, bus_cost;
        cin >> a >> b >> bus_cost;
        cost[a][b] = min(cost[a][b], bus_cost);
    }
    Solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();

    return 0;
}