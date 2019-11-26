#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr/11134

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int n1, n2;
		cin >> n1 >> n2;
		if (!(n1 % n2))	cout << n1 / n2 << '\n';
		else cout << n1 / n2 + 1 << '\n';
	}

	return 0;
}