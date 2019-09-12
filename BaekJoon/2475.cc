#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	int count = 5;
	while (count--)
	{
		int n;
		cin >> n;
		sum += n * n;
	}

	cout << sum % 10;
	return 0;
}