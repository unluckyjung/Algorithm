#include<bits/stdc++.h>
using namespace std;
//백준 5656
//https://www.acmicpc.net/problem/5656

int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cnt++;
		int n, m;
		string cmd;
		cin >> n >> cmd >> m;
		if (cmd == "E") return 0;


		if (cmd == ">") {
			cout << "Case " << cnt << ": ";
			if (n > m) cout << "true\n";
			else cout << "false\n";
		}
		else if (cmd == ">=") {
			cout << "Case " << cnt << ": ";
			if (n >= m) cout << "true\n";
			else cout << "false\n";
		}
		else if (cmd == "<") {
			cout << "Case " << cnt << ": ";
			if (n < m) cout << "true\n";
			else cout << "false\n";
		}
		else if (cmd == "<=") {
			cout << "Case " << cnt << ": ";
			if (n <= m) cout << "true\n";
			else cout << "false\n";
		}
		else if (cmd == "==") {
			cout << "Case " << cnt << ": ";
			if (n == m) cout << "true\n";
			else cout << "false\n";
		}
		else if (cmd == "!=") {
			cout << "Case " << cnt << ": ";
			if (n != m) cout << "true\n";
			else cout << "false\n";
		}


	}
	return 0;
}