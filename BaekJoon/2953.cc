#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int MAX = INT_MIN;
	int WINNER = 0;
	for (int i = 1; i <= 5; ++i) {
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		int sum = n1 + n2 + n3 + n4;

		if (sum > MAX) {
			MAX = sum;
			WINNER = i;
		}
	}

	cout << WINNER << " " << MAX;

	return 0;
}