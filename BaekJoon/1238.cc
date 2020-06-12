#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 + 2;
int n, m, x;
int cost[1002][1002];


int Get_Answer() {
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, cost[i][x] + cost[x][i]);
    }
    return answer;
}

void Floyd() {
    for (int visit = 1; visit <= n; ++visit) {
        for (int st = 1; st <= n; ++st) {
            for (int ed = 1; ed <= n; ++ed) {
                cost[st][ed] = min(cost[st][ed], cost[st][visit] + cost[visit][ed]);
            }
        }
    }
}

void Solve() {
    Floyd();
    cout << Get_Answer();
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
    cin >> n >> m >> x;
    Init();

    int a, b, _time;
    while (m--) {
        cin >> a >> b >> _time;
        cost[a][b] = _time;
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