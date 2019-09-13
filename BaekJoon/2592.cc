#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 10;
	int sum= 0;
	while (count--) {
		int num;
		cin >> num;
		sum += num;
		arr[num]++;
	}

	cout << sum / 10 << "\n";
	

	int max_index;
	int MAX = INT_MIN;
	for (int i = 10; i < 1001; i = i + 10) {
		if (arr[i] > MAX) {
			MAX = arr[i];
			max_index = i;
		}
	}

	cout << max_index;
	return 0;
}