#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 1000; ++i) {
		for (int j = i; j <= 1000; j = j + i) {
			if (arr[j] == 0 || arr[j] == 1) arr[j]++;
		}
	}

	int N;
	int count = 0;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		if (arr[num] == 1) count++;
	}
	cout << count;

	return 0;
}