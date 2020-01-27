#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int tree[MAX*3], lazy[MAX*3];
int n, m;
int cmd, qs, qe;

void propagate(int node, int s, int e) {
	if (lazy[node] % 2) {	//	짝수인경우 변화x
		tree[node] = (e - s + 1) - tree[node];
		//(e-s+1) == 가지고 있는 스위치의 수
		//tree[node] == 켜져 있는 스위치의 수
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
	}
	lazy[node] = 0;
}

void update_node(int node, int s, int e, int qs, int qe) {
	propagate(node, s, e);

	if (qs > e or qe < s) return;
	if (qs <= s and e <= qe) {
		tree[node] = (e - s + 1) - tree[node];
		if (s != e) {
			//스위치가 눌린 노드의 자식들도 스위치가 한번씩 더 눌렸다고 갱신.
			lazy[node * 2]++;
			lazy[node * 2+1]++;
		}
		return;
	}
	int mid = (s + e) / 2;
	update_node(node * 2, s, mid, qs, qe);
	update_node(node * 2+1, mid + 1, e, qs, qe);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int qs, int qe) {
	propagate(node, s, e);
	if (qs > e or qe < s)return 0;
	if (qs <= s and e <= qe) return tree[node];
	int mid = (s + e) / 2;

	int left = query(node * 2, s, mid, qs, qe);
	int right = query(node * 2+1, mid+1, e, qs, qe);
	return left + right;
}

void input() {
	cin >> n >> m;

	while (m--) {
		cin >> cmd >> qs >> qe;
		if (cmd) cout << query(1, 1, n, qs, qe) << "\n";
		else update_node(1, 1, n, qs, qe);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	input();

	return 0;
}