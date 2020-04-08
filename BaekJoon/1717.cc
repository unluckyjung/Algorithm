#include <bits/stdc++.h>
using namespace std;

int node[1000002];

int n, m;

int _find(int k) {
    if (node[k] < 0) return k;
    
    return node[k] = _find(node[k]);
}

void merge(int a, int b) {
    int a_p = _find(a);
    int b_p = _find(b);

    if (a_p == b_p) return;
    
    node[a_p] = b_p;
    return;
}

void solve() {
    int cmd, a, b;
    cin >> cmd >> a >> b;

    if (cmd == 0) merge(a, b);
    else {
        if (_find(a) == _find(b)) cout << "YES\n";
        else cout << "NO\n";
    }

}

void input() {
    cin >> n >> m;
    memset(node, -1, sizeof(node));
    while (m--) {
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}