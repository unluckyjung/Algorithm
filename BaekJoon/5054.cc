#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;


	while (cnt--) {
		int T1;
		cin >> T1;
		int MIN = INT_MAX;

		while (T1--) {
			int T2;

			cin >> T2;
			v.push_back(T2);
		}
		sort(v.begin(), v.end());
		for (const auto& i : v) {
			MIN = min(MIN , abs((i - *v.begin()) * 2) + abs((i - *v.rbegin()) * 2));
		}
		cout << MIN << "\n";
		v.clear();
	}

	return 0;
}