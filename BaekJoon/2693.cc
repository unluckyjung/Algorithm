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
		int t = 10;
		vector<int> vec;
		while (t--) {
			int num;
			cin >> num;
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		cout << vec[7] << "\n";
	}
	return 0;
}