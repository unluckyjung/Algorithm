#include<bits/stdc++.h>
using namespace std;
//백준 1453 피시방 알바
//https://www.acmicpc.net/problem/1453

int cnt;
bool visit[101];
int failman;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	while (cnt--) {
		int num; cin >> num;
		if (!visit[num]) {
			visit[num] = true;
		}
		else failman++;
	}

	cout << failman;

	return 0;
}