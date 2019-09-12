#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	int combo = 0;
	int sum = 0;
	cin >> count;
	for (int i = 1; i <= count; ++i) {
		int num;
		cin >> num;
		if (num == 1) {
			arr[i] = 1;
			sum++;
			if (arr[i - 1] == 1) {
				combo++;
			}
			sum += combo;
		}
		else combo = 0;

	}
	cout << sum;

	return 0;
}