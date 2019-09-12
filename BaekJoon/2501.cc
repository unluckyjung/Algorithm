#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int n;
	cin >> n;
	int find_num;
	cin >> find_num;

	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) v.push_back(i);
	}

	if (find_num > v.size()) {
		cout << 0;
		return 0;
	}
	cout << v[find_num - 1];

	return 0;
}