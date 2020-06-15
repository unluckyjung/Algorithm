#include <bits/stdc++.h>
using namespace std;

int n;
int node[102][102], visited[102][102];

void Print_Answer() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cout << visited[i][ii] << " ";
        }
        cout << "\n";
    }
}

#if 0
void Floyd() {
    for (int visit = 0; visit < n; ++visit) {
        for (int st = 0; st < n; st++) {
            for (int ed = 0; ed < n; ++ed) {
                if (node[st][ed]) visited[st][ed] = 1;
                else {
                    if (visited[st][visit] && visited[visit][ed]) {
                        visited[st][ed] = 1;
                    }
                }
            }
        }
    }
}

void Solve() {
    Floyd();
    Print_Answer();
}

#else


void Dfs(int start_node, int connect_node) {

    for (int nxt_node = 0; nxt_node < n; ++nxt_node) {
        if (node[connect_node][nxt_node] && !visited[start_node][nxt_node]) {
            visited[start_node][nxt_node] = true;
            Dfs(start_node, nxt_node);
        }
    }
}
#endif

void Solve() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            if (node[i][ii] && !visited[i][ii]) {
                visited[i][ii] = true;
                Dfs(i, ii);
            }
        }
    }
    Print_Answer();
}



void Input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> node[i][ii];
        }
    }
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