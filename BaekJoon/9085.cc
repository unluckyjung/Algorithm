#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		int sum = 0;
		cin >> N;
		while (N--) {
			int num;
			cin >> num;
			sum += num;
		}
		cout << sum << "\n";
	}
	return 0;
}