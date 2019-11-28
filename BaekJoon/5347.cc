#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int gcd(const int& a, const int& b) {
	if (b == 0)	return a;
	else return gcd(b, a % b);
}

int lcm(const int& a, const int& b) {
	return (long long)a * b / gcd(a, b);
}

int t;
int n1, n2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n1 >> n2;
		cout << lcm(n1, n2) << '\n';
	}
	

	return 0;
}