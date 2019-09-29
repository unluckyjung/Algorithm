#include<bits/stdc++.h>
using namespace std;

int n;

bool buy;
bool flag = true;
map<string, int> m;

int MIN = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		m[str]++;
	}

	int start = m.begin()->second;

	for (auto it = m.begin(); it != m.end(); ++it) {
		if (abs(start - it->second) >= 2) {
			flag = false;
			MIN = min(MIN, it->second);
		}
		else if (abs(start - it->second) == 1) {
			if (buy == false) {
				buy = true;
				MIN = min(MIN, it->second);
			}
			else {
				flag = false;
				MIN = min(MIN, it->second);
			}

		}
		else {
			MIN = min(MIN, it->second);
		}
	}

	if (flag == false) {
		cout << "N\n";
		cout << n << "\n";
		int pair = 0;
		for (auto it = m.begin(); it != m.end(); ++it) {
			if (it->second >= MIN)	pair++;
		}
		cout << pair << "\n";
	}

	else {
		cout << "Y\n";
		if (buy) {
			cout << n + 1 << "\n";
			cout << (n + 1) / (MIN + 1) << "\n";
		}
		else {
			cout << n << "\n";
			cout << n / MIN << "\n";
		}
	}

	return 0;
}