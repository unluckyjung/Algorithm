#include<bits/stdc++.h>
using namespace std;
//백준 2702 초6수학
//https://www.acmicpc.net/problem/2702

int cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	while (cnt--) {
		int n, m;
		cin >> n >> m;
		cout << lcm(n, m) << " " << gcd(n, m) << "\n";
	}

	return 0;
}