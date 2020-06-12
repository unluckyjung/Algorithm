#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 + 2;
int cost[102][102], path[102][102];
int n;

void Make_Path_Vec(int s, int e) {
    vector<int> path_vec;
    
    while (s != e) {
        path_vec.push_back(s);
        s = path[s][e];
    }
    path_vec.push_back(s);

    cout << (int)path_vec.size() << " ";
    for (const auto& it : path_vec) {
        cout << it << " ";
    }
    cout << "\n";
}

void Print_Path() {

    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= n; ++ii) {
            if (cost[i][ii] == INF or i == ii) cout << 0 << "\n";
            else Make_Path_Vec(i, ii);
        }
    }
}

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
                //cost[s][e] = min(cost[s][e], cost[s][visit] + cost[visit][e]);

                if(cost[s][visit] + cost[visit][e] < cost[s][e]){
                    cost[s][e] = cost[s][visit] + cost[visit][e];
                    path[s][e] = path[s][visit];

                    //path[s][e] = visit;
                    //path[visit][e] = e;
                }
            }
        }
    }
    Print_Answer();
    Print_Path();
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

        //cost[a][b] = min(cost[a][b], bus_cost);
        
        if (bus_cost < cost[a][b]) {
            cost[a][b] = bus_cost;
            path[a][b] = b;
        }
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