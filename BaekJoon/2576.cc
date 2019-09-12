#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 7;
	int sum = 0;
	int MIN = INT_MAX;
	while (count--) {
		int n;
		cin >> n;
		if (n & 1) {
			sum += n;
			MIN = min(MIN, n);
		}
	}
	if (MIN == INT_MAX) {
		cout << -1;
		return 0;
	}
	cout << sum << "\n" << MIN;
	return 0;
}