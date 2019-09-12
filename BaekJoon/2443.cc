#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int blank = 1; blank <= i; ++blank) {
			cout << " ";
		}
		for (int star = (n - i) * 2 - 1; star >= 1; --star) {
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}