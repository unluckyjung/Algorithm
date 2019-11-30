#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int t, n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int child = 0;
		while (n--) {
			int candy;	cin >> candy;
			child += candy / k;
		}
		cout << child << '\n';
	}

	return 0;
}