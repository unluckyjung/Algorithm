#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr/5789

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int num = 0;
		string str;	cin >> str;

		int len = str.size();
		if (str[len / 2] == str[(len / 2)-1]) cout << "Do-it\n";
		else cout << "Do-it-Not\n";
	}

	return 0;
}