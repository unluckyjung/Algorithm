#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int INF = 1000;
int n;
int cost[302][302];
vector<pii> lines;

void Floyd() {
    for (int visit = 1; visit <= n; ++visit) {
        for (int s = 1; s <= n; ++s) {
            for (int e = 1; e <= n; ++e) {
                cost[s][e] = min(cost[s][e], cost[s][visit] + cost[visit][e]);
                cost[e][s] = cost[s][e];
            }
        }
    }
}

void Solve() {

    Floyd();

    int q;
    cin >> q;
    int line_1, line_2;
    while (q--) {
        cin >> line_1 >> line_2;
        if (cost[line_1][line_2] == INF) cout << -1 << "\n";
        else cout << cost[line_1][line_2] << "\n";
    }
}

void Connect_Check() {
    for (int i = 0; i < n; ++i) {
        int s = lines[i].first;
        int e = lines[i].second;

        for (int ii = i + 1; ii < n; ++ii) {
            int qs = lines[ii].first;
            int qe = lines[ii].second;

            if (qs > e or qe < s) continue;
			cost[i + 1][ii + 1] = 1;
			cost[ii + 1][i + 1] = 1;
        }
    }
}

void Init() {
    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= n; ++ii) {
            if (i == ii) continue;
            cost[i][ii] = INF;
        }
    }
}

void Input() {
    cin >> n;
    Init();

    lines.resize(n);
    for (auto& line : lines) {
        cin >> line.first >> line.second;
    }
    Connect_Check();
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