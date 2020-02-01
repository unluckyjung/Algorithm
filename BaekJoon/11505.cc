#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
using namespace std;

ll tree[MAX *3];

const ll div_value = 1000000007;
int n, m, k;


void update_node(int node, int s, int e, int idx, int data) {
	if (s == e) {
		tree[node] = data % div_value;
		return;
	}

	int mid = (s + e) / 2;
	if (idx <= mid) update_node(node * 2, s, mid, idx, data);
	else update_node(node * 2 + 1, mid + 1, e, idx, data);

	tree[node] = tree[node * 2] * tree[node * 2 + 1] % div_value;
}

ll query(int node, int s, int e, int qs, int qe) {
	if (qs <= s && e <= qe)return tree[node];
	if (e < qs || qe < s)return 1;

	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, qs, qe);
	ll right = query(node * 2 + 1, mid + 1, e, qs, qe);

	return left * right % div_value;
}

void input() {
	cin >> n >> m >> k;
	int data;
	for (int i = 1; i <= n; ++i) {
		cin >> data;
		update_node(1, 1, n, i, data);
	}
}

void solve() {
	int cmd, qs, qe;

	for (int i = 0; i < m + k; ++i) {
		cin >> cmd >> qs >> qe;
		if (cmd == 1)	update_node(1, 1, n, qs, qe);
		else cout << query(1, 1, n, qs, qe) << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}