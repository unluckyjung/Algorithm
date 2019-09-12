#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int blank = n - i; blank >= 1; --blank) {
			cout << " ";
		}
		for (int star = 1; star <= i; ++star) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i < n; ++i) {
		for (int blank = 1; blank <= i; ++blank) {
			cout << " ";
		}
		for (int star = n - i; star > 0; --star) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}