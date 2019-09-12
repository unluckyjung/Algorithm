#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n * 2 - 1; ++i) {
		if (i <= n) {
			for (int j = 1; j <= i; ++j) cout << "*";
		}
		else {
			for (int j = n * 2 - i; j >= 1; --j) cout << "*";
		}
		cout << "\n";
	}
	return 0;
}