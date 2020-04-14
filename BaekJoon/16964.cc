#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<int> node[100002];
bool visit[100002];
int n;

queue<int> input_q;

bool dfs(int cur) {

    unordered_set<int> s;
    for (int connect : node[cur]) {
        if (visit[connect]) continue;
        s.insert(connect);
    }

    for (int i = 0; i < (int)s.size(); ++i) {
        if (input_q.empty()) return false;
        int nxt = input_q.front(); input_q.pop();

        if (s.find(nxt) == s.end()) return false;
        visit[nxt] = true;

        if (!dfs(nxt)) return false;
    }

    return true;
}


bool solve() {
    int start = input_q.front(); input_q.pop();
    if (start != 1) return false;

    visit[start] = true;
    return dfs(start);
}

void input() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        input_q.push(num);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    if (solve())  cout << "1\n";
    else cout << "0\n";

    return 0;
}