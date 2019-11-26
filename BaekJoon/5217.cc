#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int n;	cin >> n;
		bool flag = false;
		cout << "Pairs for " << n << ':';
		for (int i = 0; i < n; ++i) {
			for (int ii = i + 1; ii < n; ++ii) {
				if ((i + ii) == n) {
					if (flag)	cout << ',';
					cout << " " << i << " " << ii;
					flag = true;
				}
			}
		}
		cout << '\n';
	}

	return 0;
}