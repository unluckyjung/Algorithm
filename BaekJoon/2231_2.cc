#include<bits/stdc++.h>
using namespace std;
//백준 분해합 2231
//https://www.acmicpc.net/problem/2231

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num; cin >> num;
	int result = 0;
	for (int i = 0; i <= 1000000; ++i) {
		//생성자는 항상 분해합보다 작다.
		//모든 경우를 탐색한다.
		int ans = i;
		int temp = i;

		while (temp!=0) {
			ans += temp % 10;
			//원래 수에 각 자리의 수를 다 더한다.
			temp /= 10;
		}
		if (ans == num) {
			cout << i; return 0;
		}
	}

	cout << 0;

	return 0;
}