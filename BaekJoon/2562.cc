#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int MAX = INT_MIN;
	int n = 9;
	while (n--) {
		int num;
		cin >> num;
		MAX = max(MAX, num);
		v.push_back(num);
	}
	cout << MAX << "\n";
	auto it = find(v.begin(), v.end(), MAX);
	cout << it - v.begin() + 1;
	return 0;
}