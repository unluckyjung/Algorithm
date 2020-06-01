#if 00

#include <bits/stdc++.h>
using namespace std;

vector<int> node[52], party[52], truth_mans;
bool visit[52];
bool visit_check[52][52];

int n, m, k;

bool IsLie(int party_n) {
    for (const auto& man : party[party_n]) {
        if (visit[man]) return false;
    }
    return true;
}

void Dfs(int cur_man) {
    for (const auto &nxt_man : node[cur_man]) {
        if (visit[nxt_man]) continue;
        visit[nxt_man] = true;
        Dfs(nxt_man);
    }
}

void Truth_spread() {
    for (const auto& man : truth_mans) {
        visit[man] = true;
        Dfs(man);
    }
}

void Make_Relationship(int party_n) {
	for (int i = 0; i < (int)party[party_n].size(); ++i) {
		for (int ii = i + 1; ii < (int)party[party_n].size(); ++ii) {
            int a = party[party_n][i];
            int b = party[party_n][ii];

            if (visit_check[a][b]) continue;
            visit_check[a][b] = true;
            visit_check[b][a] = true;
            node[a].push_back(b);
            node[b].push_back(a);
		}
    }
}

void Solve() {
    for (int i = 0; i < m; ++i) {
        Make_Relationship(i);
    }
    Truth_spread();

    int answer = 0;
    for (int i = 0; i < m; ++i) {
        if (IsLie(i)) answer++;
    }
    cout << answer << "\n";
}

void Input() {
    cin >> n >> m;
    cin >> k;

    truth_mans.resize(k);
    for (auto& man : truth_mans) {
        cin >> man;
    }

    int party_mans;
    for (int i = 0; i < m; ++i) {
        cin >> party_mans;
        party[i].resize(party_mans);
        for (auto& man : party[i]) {
            cin >> man;
        }
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

#else


#include <bits/stdc++.h>
using namespace std;

vector<int> node[52], party[52], truth_mans;
bool visit[52];

int n, m, k;

bool IsLie(int party_n) {
    for (const auto& man : party[party_n]) {
        if (visit[man]) return false;
    }
    return true;
}

void Dfs(int cur_man) {
    for (const auto &include_party : node[cur_man]) {
        for (const auto& nxt_man : party[include_party]) {
            if (visit[nxt_man]) continue;
            visit[nxt_man] = true;
            Dfs(nxt_man);
        }
    }
}

void Truth_spread() {
    for (const auto& man : truth_mans) {
        visit[man] = true;
        Dfs(man);
    }
}

void Solve() {
    Truth_spread();

    int answer = 0;
    for (int i = 0; i < m; ++i) {
        if (IsLie(i)) answer++;
    }
    cout << answer << "\n";
}

void Input() {
    cin >> n >> m;
    cin >> k;

    truth_mans.resize(k);
    for (auto& man : truth_mans) {
        cin >> man;
    }

    int party_mans;
    for (int party_n = 0; party_n < m; ++party_n) {
        cin >> party_mans;

        int man;
        while(party_mans--) {
            cin >> man;
            party[party_n].push_back(man);
            node[man].push_back(party_n);
        }
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

#endif