#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	int sum = 0;
	cin >> count;
	while (count--) {
		int num;
		cin >> num;
		sum += num - 1;
	}

	cout << sum + 1;
	return 0;
}