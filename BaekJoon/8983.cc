#include <bits/stdc++.h>
using namespace std;

int range_num;
int animal_num;
int shoot_range;

int answer;
vector<int> vec;

void input() {
	cin >> range_num >> animal_num >> shoot_range;
	for (int i = 0; i < range_num; ++i) {
		int n;	cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
}

void solve() {
	for (int i = 0; i < animal_num; ++i) {
		int x, y;
		cin >> x >> y;
		if (y > shoot_range)continue;
		int range_min = min(x - y + shoot_range, x + y - shoot_range);
		int range_max = max(x - y + shoot_range, x + y - shoot_range);

		vector<int>::iterator it = lower_bound(vec.begin(), vec.end(), range_min);
		if (it == vec.end() || *it > range_max)continue;
		answer++;
	}
	cout << answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}