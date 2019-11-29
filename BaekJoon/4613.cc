#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	while (1) {
		getline(cin, s);
		if (s == "#")break;

		int sum = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i])) {
				sum += (i + 1) * (s[i] - 'A' + 1);
			}
		}

		cout << sum << "\n";
	}

	return 0;
}
