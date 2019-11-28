#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int a, b, c, d;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c >> d;
	cout << min(a + d, b + c);
	return 0;
}