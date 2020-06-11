#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> node[1002], answer;
queue<int> q;

int node_indegree[1002];


void Solve() {
    for (int i = 1; i <= n; ++i) {
        if (node_indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        auto cur = q.front();   q.pop();
        answer.push_back(cur);

        for (const auto &nxt : node[cur]) {
            node_indegree[nxt]--;
            if (node_indegree[nxt] == 0) q.push(nxt);
        }
    }
    
    if ((int)answer.size() != n) {
        cout << 0 << "\n";
        return;
    }
    else {
        for (const int& ans : answer) {
            cout << ans << "\n";
        }
    }
}

void Manager_Input(int singer_n) {

    int front_singer, singer;
    for (int i = 0; i < singer_n; ++i) {
        cin >> singer;
        if (i == 0) {
            front_singer = singer;
            continue;
        }
        
        node[front_singer].push_back(singer);
        node_indegree[singer]++;
        front_singer = singer;
    }
}

void Input() {
    cin >> n >> m;

    int singer_n;
    while (m--) {
        cin >> singer_n;
        Manager_Input(singer_n);
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