#include <bits/stdc++.h>
using namespace std;

int arr[2][6];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, K;

	cin >> N >> K;
	int S, Y;
	while (N--) {
		cin >> S >> Y;
		arr[S][Y - 1] ++;
	}

	int sum = 0;
	for (int i = 0; i < 2; ++i) {
		for (int ii = 0; ii < 6; ++ii) {
			sum += arr[i][ii] / 2;
			if (arr[i][ii] % 2 != 0) sum++;
		}
	}

	cout << sum;

	return 0;
}