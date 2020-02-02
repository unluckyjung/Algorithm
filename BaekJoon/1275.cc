#include <bits/stdc++.h>
#define ll long long
#define MAX 100001

using namespace std;

ll tree[MAX * 3];

int n, q;

void update_node(int node, int s, int e, int idx, int data) {
	if (s == e) {
		tree[node] = data;
		return;
	}
	int mid = (s + e) / 2;
	if (idx <= mid)	update_node(node * 2, s, mid, idx, data);
	else update_node(node * 2 + 1, mid + 1, e, idx, data);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int qs, int qe) {
	if (qs <= s && e <= qe)	return tree[node];
	if (e < qs || qe < s) return 0;
	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, qs, qe);
	ll right = query(node * 2 + 1, mid + 1, e, qs, qe);

	return left + right;
}

void input() {
	cin >> n >> q;
	int data;
	for (int i = 1; i <= n; ++i) {
		cin >> data;
		update_node(1, 1, n, i, data);
	}
}

void solve() {
	int qs, qe;
	int idx, data;
	while (q--) {
		cin >> qs >> qe >> idx >> data;
		int real_qs = min(qs, qe);
		int real_qe = max(qs, qe);
		cout << query(1, 1, n, real_qs, real_qe) << "\n";
		update_node(1, 1, n, idx, data);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}