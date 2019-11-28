#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int t;
double n1, n2, n3, n4, n5;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);

	cin >> t;
	while (t--) {
		cin >> n1 >> n2 >> n3 >> n4 >> n5;
		cout << '$' << n1 * 350.34 + n2 * 230.90 + n3 * 190.55 + n4 * 125.30 + n5 * 180.90 << '\n';
	}
	
	return 0;
}