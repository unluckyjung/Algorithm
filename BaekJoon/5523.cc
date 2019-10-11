#include<bits/stdc++.h>
using namespace std;
//백준 경기결과 5523
//https://www.acmicpc.net/problem/5523

int A, B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt; cin >> cnt;
	while (cnt--) {
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 > n2)	A++;
		if (n2 > n1)	B++;
	}
	cout << A << " " << B;

	return 0;
}