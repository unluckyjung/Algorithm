#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000
using namespace std;

ll tree[MAX + 1];

ll answer;
ll n, want_tree;

void input() {
	cin >> n >> want_tree;
	for (int i = 0; i < n; ++i) {
		cin >> tree[i];
		answer = max(answer, tree[i]);
	}
}

ll tree_cut(ll h) {
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		if (tree[i] <= h)continue;
		sum += (tree[i] - h);
	}
	return sum;
}


void solve() {
	ll s = 0;
	ll e = answer;
	ll mid;
	while (s <= e) {
		mid = (s + e) / 2;

		ll tree_sum = tree_cut(mid);
		if (tree_sum == want_tree) {
			cout << mid;
			return;
		}
		else if (tree_sum > want_tree) {
			answer = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}

	cout << answer;
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