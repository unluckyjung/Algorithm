#include<bits/stdc++.h>
using namespace std;
//백준 시험점수 5596
//https://www.acmicpc.net/problem/5596

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 4; ++i) {
		int num;
		cin >> num; sum1 += num;
	}

	for (int i = 0; i < 4; ++i) {
		int num;
		cin >> num; sum2 += num;
	}

	cout << max(sum1, sum2);

	return 0;
}