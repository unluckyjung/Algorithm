#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	string str;
	while (n--) {
		cin >> str;
		mp[str]++;
	}

	while (m--) {
		cin >> str;
		mp[str]++;
	}

	queue<string> ans;
	int sum = 0;
	for (auto s: mp) {
		if (s.second == 2) {
			sum++;
			ans.push(s.first);
		}
	}

	cout << sum << '\n';
	while (!ans.empty()) {
		cout << ans.front() << '\n';
		ans.pop();
	}
	return 0;
}