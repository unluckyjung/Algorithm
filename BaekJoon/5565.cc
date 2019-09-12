#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum, price;
	int count = 9;

	cin >> sum;
	while (count--) {
		cin >> price;
		sum -= price;
	}
	cout << sum;
	return 0;
}