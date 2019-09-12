#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	int combo = 0;
	int sum = 0;
	cin >> count;
	while (count--) {
		int num;
		cin >> num;
		if (num) sum += ++combo;
		else combo = 0;
	}
	cout << sum;
	return 0;
}