#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	while (cnt--) {
		int stu;
		int chair;
		vector<int> vec;
		cin >> stu >> chair;
		while (stu--) {
			int want;
			cin >> want;
			vec.push_back(want);
		}
		int sum = 0;
		for (int i = 1; i <= chair; ++i) {
			int late = count(vec.begin(), vec.end(), i);
			if (late > 1) sum += late - 1;
		}
		cout << sum << "\n";
	}
	return 0;
}