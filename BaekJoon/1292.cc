#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n1, n2;
	int sum = 0;
	cin >> n1 >> n2;

	for (int i = n1; i <= n2; ++i) {
		sum += floor(sqrt(2 * i) + 0.5);
	}
	cout << sum;

	return 0;
}