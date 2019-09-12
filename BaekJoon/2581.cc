#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 10000; ++i) {
		for (int j = i; j <= 10000; j = j + i) {
			if (arr[j] == 0 || arr[j] == 1) arr[j]++;
		}
	}

	int n1, n2;
	int MIN = INT_MAX;
	int flag = 0;
	int sum = 0;
	cin >> n1 >> n2;
	for (int i = n1; i <= n2; ++i) {
		if (arr[i] == 1) {
			flag = 1;
			sum += i;
			MIN = min(i, MIN);
		}
	}

	if (flag == 0) {
		cout << -1;
		return 0;
	}

	cout << sum << "\n" << MIN;

	return 0;
}