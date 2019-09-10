#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;


	long long n0 = 0;
	long long n1 = 1;
	long long n2 = 0;

	for (int i = 2; i <= n; ++i) {
		n2 = n0 + n1;
		n0 = n1;
		n1 = n2;
	}
	return n2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << fibonacci(n);

	return 0;
}