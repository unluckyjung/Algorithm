#include <bits/stdc++.h>
#include <regex>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, s);

	int sum = 1;
	if (s[0] == ' ')	sum = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') sum++;
		if ((i == s.size() - 1) && s[i] == ' ')sum--;
	}
	cout << sum;
	return 0;
}
