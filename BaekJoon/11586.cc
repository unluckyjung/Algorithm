#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int n;
int upset;
vector<string> mirror;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		mirror.push_back(str);
	}

	cin >> upset;
	
	if (upset == 1) {
		for (string &str : mirror) {
			cout << str << '\n';
		}
	}
	else if (upset == 2) {
		for (string &str : mirror) {
			reverse(str.begin(), str.end());
			cout << str << '\n';
		}
	}
	else {
		//for (auto it = mirror.rbegin(); it != mirror.rend(); ++it) {
			for (vector<string>::reverse_iterator it = mirror.rbegin(); it != mirror.rend(); ++it) {
			cout << *it << '\n';
		}
	}

	return 0;
}