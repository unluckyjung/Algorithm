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
		vector<int> vec;
		int cnt = 5;

		while (cnt--) {	//while이 음수여도 돌아간다 주의
			int num;
			cin >> num;
			vec.push_back(num);

		}
		sort(vec.begin(), vec.end());

		if (vec[3] - vec[1] >= 4) cout << "KIN\n";
		else {
			int sum = 0;
			for (int i = 1; i < 4; ++i) {
				sum += vec[i];
			}
			cout << sum << "\n";
		}
	}

	return 0;
}