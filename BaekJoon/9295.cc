#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;
	for (int i = 1; i <= count; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		printf("Case %d: %d\n", i, n1 + n2);
	}

	return 0;
}