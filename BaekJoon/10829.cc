#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

long long n;

void to_binary(long long n) {

	string str;
	while (n) {
		str.push_back(n % 2 +'0');
		n = n / 2;
	}
	reverse(str.begin(), str.end());
	cout << str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	to_binary(n);

	return 0;
}