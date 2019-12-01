#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int n; cin >> n;

		vector<pair<int, int>> result;

		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int vote;	cin >> vote;
			sum += vote;
			result.push_back({ vote, i });
		}

		int over = sum / 2;

		sort(result.begin(), result.end(), greater<pair<int, int>>());
		if (result[0].first == result[1].first) {
			cout << "no winner\n";
		}
		else if (result[0].first > over) {
			cout << "majority winner " << result[0].second + 1 << "\n";
		}
		else {
			cout << "minority winner " << result[0].second + 1 << "\n";
		}

	}
	return 0;
}