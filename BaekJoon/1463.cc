#include <bits/stdc++.h>
using namespace std;
//백준 1463 1로만들기.
//https://www.acmicpc.net/problem/1463

bool visit[1000002];
int n;

void bfs(int n) {
	queue<pair<int, int>> q;
	visit[n] = true; q.push({ n, 0 });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int number = cur.first;
		int cnt = cur.second;

		if (number == 1) {
			cout << cnt;
			return;
		}

		if (visit[number - 1] == false) {
			visit[number - 1] = true;
			q.push({ number - 1, cnt + 1 });
		}
		if (visit[number / 2] == false and number % 2 == 0) {
			visit[number / 2] = true;
			q.push({ number / 2, cnt + 1 });
		}
		if (visit[number / 3] == false and number % 3 == 0) {
			visit[number / 3] = true;
			q.push({ number / 3, cnt + 1 });
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	bfs(n);


	return 0;
}