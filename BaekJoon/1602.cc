#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int INF = 1e9;
int cost[502][502], dog_cost[502][502];
int dog[10002];
vector<pii> dog_p;

int n, m, q;

void Floyd() {
    for (int i = 0; i < n; ++i) {
        int visit = dog_p[i].second;

        for (int s = 1; s <= n; ++s) {
            for (int e = 1; e <= n; ++e) {
                int dog_attack = max(dog_cost[s][visit], dog_cost[visit][e]);
                int cur_dog_attack = dog_cost[s][e];

                if (cost[s][visit] + cost[visit][e] + dog_attack < cost[s][e] + cur_dog_attack) {
                    cost[s][e] = cost[e][s] = cost[s][visit] + cost[visit][e];
                    dog_cost[s][e] = dog_cost[e][s] = dog_attack;
                }
            }
        }
    }
}


void Solve() {
    Floyd();

    int s, e;
    while (q--) {
        cin >> s >> e;
        if (cost[s][e] == INF) cout << -1 << "\n";
        else cout << cost[s][e] + dog_cost[s][e] << "\n";
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
    cin >> n >> m >> q;
    Init();
    for (int i = 1; i <= n; ++i) {
        cin >> dog[i];
        dog_p.push_back({ dog[i],i });
    }

    sort(dog_p.begin(), dog_p.end());

    int a, b, _cost;
    while (m--) {
        cin >> a >> b >> _cost;
        cost[a][b] = cost[b][a] = _cost;
        dog_cost[a][b] = dog_cost[b][a] = max(dog[a], dog[b]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}