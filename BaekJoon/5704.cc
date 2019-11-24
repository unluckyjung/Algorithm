#include<bits/stdc++.h>
#include<regex>
using namespace std;

int sum;
int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "*") {
			break;
		}

		map<char, int> m;
		for (char c : s) {
			m[c]++;
		}

		bool flag = true;
		for (char c = 'a'; c <= 'z'; ++c) {
			if (m[c] == 0) {
				cout << 'N' << '\n';
				flag = false;
				break;
			}
		}

		if (flag) cout << 'Y' << '\n';
		
	}
	return 0;
}