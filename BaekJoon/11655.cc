#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	while (cnt--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		for (int i = n; i <= m; ++i) {
			string str = to_string(i);
			sum += count(str.begin(), str.end(), '0');
		}
		cout << sum << "\n";
	}

	return 0;
}