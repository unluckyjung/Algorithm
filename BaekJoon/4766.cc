#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

double degree, cnt, before;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);

	cin >> before;

	while (cin >> degree) {
		if (abs(degree - 999) <= 0.00001)break;
		cout << degree - before << '\n';
		before = degree;
	}
	
	return 0;
}