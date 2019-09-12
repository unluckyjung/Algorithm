#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int score;
	int sum = 0;
	while (cin >> score) {
		sum += score;
	}
	cout << sum;

	return 0;
}