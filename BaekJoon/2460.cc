#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 10;
	int MAX = INT_MIN;
	int sum = 0;

	while (count--) {
		int out, in;
		cin >> out >> in;
		sum += in - out;
		MAX = max(MAX, sum);
	}
	cout << MAX;
	return 0;
}