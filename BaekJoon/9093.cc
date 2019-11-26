#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int T;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	cin.ignore();
	while (T--) {
		string str;
		getline(cin, str);
		
		int cut = 0;
		for (int i = 0; i < (int)str.size(); ++i) {
			if (str[i] == ' ') {
				string tmp = str.substr(cut, i-cut);
				cut = i+1;
				for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
					cout << *it;
				}
				cout << ' ';
			}
			else if (i == ((int)str.size() - 1)) {
				string tmp = str.substr(cut);
				for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
					cout << *it;
				}
				cout << '\n';
			}
		}
	}
	

	return 0;
}