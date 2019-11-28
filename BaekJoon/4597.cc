#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string str;	cin >> str;

		if (str == "#")	break;

		int cnt = 0;
		for (char c : str) {
			if (c == 'e') {
				if (cnt % 2 == 0)	cout << "0\n";
				else cout << "1\n";
				break;
			}
			else if (c == 'o') {
				if (cnt % 2 != 0)	cout << "0\n";
				else cout << "1\n";
				break;
			}
			else if (c == '1')	cnt++;

			cout << c;
		}
	}

	return 0;
}