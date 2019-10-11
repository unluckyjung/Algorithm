#include<bits/stdc++.h>
using namespace std;
//백준 유학금지 2789
//https://www.acmicpc.net/problem/2789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str; cin >> str;
	string check = "CAMBRIDGE";

	for (int i = 0; i < (int)str.size(); ++i) {
		bool warning = false;
		for (int ii = 0; ii < (int)check.size(); ++ii) {
			if (str[i] == check[ii]) {
				warning = true; break;
			}
		}
		if (!warning) cout << str[i];
	}
	return 0;
}