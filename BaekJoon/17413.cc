#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> s;
int str_len;

void print_char() {
	while (!s.empty()) {
		cout << s.top(); s.pop();
	}
}
void solve() {
	for (int i = 0; i < str_len; ++i) {
		if (str[i] == ' ') {
			print_char();
			cout << ' ';
		}
		else if (str[i] == '<') {
			print_char();
			int ii;
			for (ii = i; ii < str_len; ++ii) {
				cout << str[ii];
				if (str[ii] == '>')break;
			}
			i = ii;
		}
		else s.push(str[i]);
	}
	print_char();
}


void input() {
	getline(cin, str);
	str_len = str.size();
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