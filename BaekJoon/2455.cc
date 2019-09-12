#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 4;
	int sum = 0;
	int MAX = INT_MIN;

	while (count--) {
		int reduce, add;
		cin >> reduce >> add;

		sum -= reduce;
		sum += add;

		MAX = max(sum, MAX);
	}
	cout << MAX;
	return 0;
}