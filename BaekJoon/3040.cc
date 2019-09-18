#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//clock_t start, stop;
	//start = clock();
	////function
	//stop = clock();

	vector<int> vec;

	int cnt = 9;
	int sum = 0;
	while (cnt--) {
		int num;
		cin >> num;
		vec.push_back(num);
		sum += num;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - vec[i] - vec[j] == 100) {
				for (const int& it : vec) {
					if (it == vec[i] or it == vec[j])continue;
					cout << it << "\n";
				}
				return 0;
			}
		}
	}

	return 0;
}