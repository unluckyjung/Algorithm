#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

int tree[MAX * 3], lazy[MAX * 3];

int n, m;

void propagate(int node, int s, int e) {
    if (lazy[node] != 0) {
        tree[node] ^= lazy[node] * ((e-s+1) % 2);
        if (s != e) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2+1] ^= lazy[node];
        }
    }
    lazy[node] = 0;
}

void update_node(int node, int s, int e, int qs, int qe, int data) {
    propagate(node, s, e);

    if (qs > e or s > qe)return;
    if (qs <= s and e <= qe) {
        tree[node] ^= data * ((e - s + 1) % 2);
        if (s != e) {
            lazy[node * 2] ^= data;
            lazy[node * 2 + 1] ^= data;
        }
        return;
    }
    int mid = (s + e) / 2;
    update_node(node * 2, s, mid, qs, qe, data);
    update_node(node * 2 + 1, mid + 1, e, qs, qe, data);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int s, int e, int qs, int qe) {
    propagate(node, s, e);

    if (qs <= s and e <= qe)return tree[node];
    if (qs > e or s > qe)return 0;

    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, qs, qe);
    int right = query(node * 2 + 1, mid + 1, e, qs, qe);
    return left ^ right;
}

void solve(int m) {
    int t, a, b, data;
    int qs, qe;
    while (m--) {
        cin >> t >> a >> b;
        qs = min(a, b);
        qe = max(a, b);

        if (t == 1) {
            cin >> data;
            update_node(1, 1, n, qs+1, qe+1, data);
        }
        else cout << query(1, 1, n, qs+1, qe+1) << "\n";
    }
}

void input() {
    cin >> n;
    int data;
    for (int i = 1; i <= n; ++i) {
        cin >> data;
        update_node(1, 1, n, i, i, data);
    }
    cin >> m;
    solve(m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();

    return 0;
}