#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	int sum = 0;
	int min = 0;

	int flag = 0;
	cin >> M >> N;

	for (int i = 1; i * i <= N; ++i) {
		if (i * i >= M) {
			sum += i * i;
			if (flag == 0) {
				min = i * i;
			}
			flag = 1;
		}
	}

	if (sum == 0) {
		cout << -1;
		return 0;
	}

	cout << sum << "\n";
	cout << min;
	return 0;
}