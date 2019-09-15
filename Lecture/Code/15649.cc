#include <bits/stdc++.h>
using namespace std;

bool check[10];
int a[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; ++i) {
			cout << a[i];
			if (i != m - 1) cout << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= n; ++i) {
			if (check[i]) continue;
			check[i] = true;
			a[index] = i;
			go(index + 1, n, m);
			check[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	go(0, n, m);


	return 0;
}