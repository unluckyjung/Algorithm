#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 3;

	while (cnt--) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	for (const int& i : vec)
		cout << i << " ";
	return 0;
}