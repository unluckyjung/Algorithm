#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX 1000001

ll tree[MAX * 3];
ll lazy[MAX * 3];


int n, m, k;


void propagate(int node, int s, int e) {
    if (lazy[node] != 0) {
        //tree[node] += lazy[node];
        //lazy를 잘 생각해봐라.. 가지고 있는 leaf 노드 개수 만큼 곱해야함.
        tree[node] += lazy[node] * ((ll)e - s + 1);
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void new_node(int node, int s, int e, int idx, ll data) {
    propagate(node, s, e);
    if (s == e) {
        tree[node] = data;
        return;
    }
    int mid = (s + e) / 2;
    if (idx <= mid) new_node(node * 2, s, mid, idx, data);
    else new_node(node * 2 + 1, mid + 1, e, idx, data);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_node(int node, int s, int e, int qs, int qe, ll data) {
    propagate(node, s, e);

    if (qs > e or s > qe) return;
    if (qs <= s and e <= qe) {
        //tree[node] += data;
        tree[node] += data * ((ll)e - s + 1);
        if (s != e) {
            lazy[node * 2] += data;
            lazy[node * 2 + 1] +=data;
        }
        return;
    }
    int mid = (s + e) / 2;
    update_node(node * 2, s, mid, qs, qe, data);
    update_node(node * 2 + 1, mid + 1, e, qs, qe, data);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

#if 0
//update node + new node
//근데 더 느림 288 > 408
void update_node(int node, int s, int e, int qs, int qe, ll data) {
    propagate(node, s, e);

    if (qs > e or s > qe) return;
    if (qs <= s and e <= qe) {
        tree[node] += data * ((ll)e - s + 1);
        if (s != e) {
            lazy[node * 2] += data;
            lazy[node * 2 + 1] +=data;
        }
        return;
    }
    int mid = (s + e) / 2;
    update_node(node * 2, s, mid, qs, qe, data);
    update_node(node * 2 + 1, mid + 1, e, qs, qe, data);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}
#endif

ll query(int node, int s, int e, int qs, int qe) {
    propagate(node, s, e);

    if (qs <= s and e <= qe) return tree[node];
    if (qs > e or s > qe) return 0;

    int mid = (s + e) / 2;
    ll left = query(node * 2, s, mid, qs, qe);
    ll right = query(node * 2 + 1, mid + 1, e, qs, qe);
    return left + right;
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        ll data; cin >> data;
        new_node(1, 1, n, i, data);
    }

    for (int i = 0; i < m + k; ++i) {
        int cmd, qs, qe;
        cin >> cmd;

        ll data;
        if (cmd == 1) {
            cin >> qs >> qe >> data;
            update_node(1, 1, n, qs, qe, data);
        }
        else if (cmd == 2) {
            cin >> qs >> qe;
            cout << query(1, 1, n, qs, qe) << "\n";
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();

    return 0;
}