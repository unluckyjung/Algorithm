#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int fn;
	cin >> fn;
	cout << count(v.begin(), v.end(), fn);

	return 0;
}