#include<bits/stdc++.h>
using namespace std;
//백준 배수찾기 4504
//https://www.acmicpc.net/problem/4504

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (1) {
		int num; cin >> num;
		if (num == 0)return 0;

		if (num % n == 0)
			cout << num << " is a multiple of " << n <<".\n";
		else
			cout << num << " is NOT a multiple of " << n << ".\n";

	}

	return 0;
}