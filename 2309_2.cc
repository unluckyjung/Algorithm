#include <bits/stdc++.h>
using namespace std;

int arr[9];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		int num;
		cin >> num;
		arr[i] = num;
		sum += num;
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - arr[i] - arr[j] == 100) {
				for (int it : arr) {
					if (it == arr[i] or it == arr[j])continue;
					cout << it << "\n";
				}
				return 0;//여기서 종류 안하면 왜맞틀 하게됨.
			}
		}
	}

	return 0;
}