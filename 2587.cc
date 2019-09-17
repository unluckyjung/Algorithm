#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 5;
	int sum = 0;
	while (cnt--) {
		int num;
		cin >> num;
		vec.push_back(num);
		sum += num;
	}

	sort(vec.begin(), vec.end());

	cout << sum / 5 << "\n";
	cout << vec[2];
	return 0;
}