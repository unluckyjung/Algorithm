#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll tree[3000000];

void update_node(ll node, ll s, ll e, ll idx, ll data) {
    if (s == e) {
        tree[node] = data;
        return;
    }
    ll mid = s + (e - s) / 2;
    if (idx <= mid) update_node(node * 2, s, mid, idx, data);
    else update_node(node * 2 + 1, mid + 1, e, idx, data);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll s, ll e, ll qs, ll qe) {
    if (qs <= s and e <= qe) return tree[node];
    if (qs > e or s > qe) return 0;

    ll mid = s + (e - s) / 2;
    ll left = query(node * 2, s, mid, qs, qe);
    ll right = query(node * 2 + 1, mid + 1, e, qs, qe);
    return left + right;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        int data; cin >> data;
        update_node(1, 1, n, i, data);
    }

    for (int i = 0; i < m + k; ++i) {
        ll cmd, b, c;
        cin >> cmd >> b >> c;
        if (cmd == 1) update_node(1, 1, n, b, c);
        else if (cmd == 2) cout << query(1, 1, n, b, c) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();

    return 0;
}