#include<bits/stdc++.h>
using namespace std;
//백준 가위 바위 보? 4493
//https://www.acmicpc.net/problem/4493

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int cnt; cin >> cnt;

		int p1 = 0, p2 = 0;
		while (cnt--) {
			char n1, n2;
			cin >> n1 >> n2;
			if (n1 == n2)continue;
			if (n1 == 'R') {
				if (n2 == 'S') p1++;
				else p2++;
			}
			else if (n1 == 'P') {
				if (n2 == 'R')p1++;
				else p2++;
			}
			else if (n1 == 'S') {
				if (n2 == 'P')p1++;
				else p2++;
			}
		}
		if (p1 == p2) cout << "TIE\n";
		else if (p1 > p2) cout << "Player 1\n";
		else cout << "Player 2\n";
	}

	return 0;
}