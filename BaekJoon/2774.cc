#include<bits/stdc++.h>
using namespace std;
//백준 아름다운수 2774
//https://www.acmicpc.net/problem/2774

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt; cin >> cnt;
	while (cnt--) {
		string num; cin >> num;
		int sum = 0;
		for (char i = '0'; i <= '9'; ++i) {
			if (num.find(i) != -1)	sum++;
		}
		cout << sum << "\n";
	}
	return 0;
}