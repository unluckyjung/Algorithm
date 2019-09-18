#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string num;
	int cnt;

	string answer;
	cin >> num >> cnt;

	for (int i = 0; i < stoi(num); ++i) {
		answer += num;
		if ((int)answer.size() > cnt) {
			for (int ii = 0; ii < cnt; ++ii) cout << answer[ii];
			return 0;
		}
	}
	
	cout << answer;
	return 0;
}