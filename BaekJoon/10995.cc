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
		if (!(i & 1)) {
			for (int star = 1; star <= n; ++star) cout << " *";
		}
		else {
			for (int star = 1; star <= n; ++star) cout << "* ";
		}
		cout << "\n";
	}

	return 0;
}