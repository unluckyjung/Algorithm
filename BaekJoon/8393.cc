#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 0;
	while (N--) {
		sum += N + 1;
	}
	cout << sum;
	return 0;
}