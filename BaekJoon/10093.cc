#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n1, n2;
	cin >> n1 >> n2;

	if (n1 == n2) {
		cout << 0;
		return 0;
	}

	cout << abs(n2 - n1) - 1 << "\n";

	for (long long i = min(n1,n2)+1; i < max(n1,n2); ++i) {
		cout << i << " ";
	}
	return 0;
}