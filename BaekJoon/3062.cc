#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

bool symmertry(string &s) {
	for (int i = 0; i <= (int)s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}
bool issymmetry(string &s) {
	int n1 = stoi(s);
	reverse(s.begin(), s.end());
	int n2 = stoi(s);
	string sum = to_string(n1 + n2);

	return symmertry(sum);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		if (issymmetry(str))	cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}