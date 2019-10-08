#include<bits/stdc++.h>
using namespace std;
//백준 2845
//https://www.acmicpc.net/problem/2845

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n1, n2;
	cin >> n1 >> n2;

	int cnt = 5;
	while (cnt--) {
		int num;
		cin >> num;
		cout << num - n1 * n2 << " ";
	}

	return 0;
}