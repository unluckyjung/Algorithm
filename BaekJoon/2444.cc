#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n*2-1; ++i) {
		int blank = abs(n - i);
		while (blank--) cout << " ";
		for (int j = 1; j <= i * 2 - 1; ++j) {
			if (i > n) {
				break;
			}
			cout << "*";
		}
		if (i > n) {
			for (int j = (n * 2 - i) * 2 - 1; j >= 1; --j) {
				cout << "*";
			}
		}
		cout << "\n";
	}

	return 0;
}