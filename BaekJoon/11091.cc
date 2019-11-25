#include<bits/stdc++.h>
#include<regex>
using namespace std;

int main() {

	int n; cin >> n;
	cin.ignore();

	string s;
	while (getline(cin, s)) {
		
		map<char, int> m;
		for (char c : s) {
			if (isalpha(c)) {
				m[tolower(c)]++;
			}
		}
		bool flag = false;
		string ans;
		for (char c = 'a'; c <= 'z'; ++c) {
			if (m[c]== 0) {
				flag = true;
				ans.push_back(c);
			}
		}

		if (flag) cout << "missing" << " " << ans << '\n';
		else cout << "pangram\n";
	}
	return 0;
}