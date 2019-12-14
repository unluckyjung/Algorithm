#include<bits/stdc++.h>
using namespace std;

int n, k;

int dist[100001];
int way[100001];

queue<int> q;
void bfs() {
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == k) {
			cout << dist[k] << "\n" << way[k] << "\n";
			return;
		}

		int next[] = { cur - 1, cur + 1, cur * 2 };

		for (int dir = 0; dir < 3; ++dir) {
			int nx = next[dir];

			if (nx < 0 or nx > 100000)continue;
			if (dist[nx] == -1) {
				dist[nx] = dist[cur] + 1;
				way[nx] += way[cur];
				q.push(nx);
			}
			else if (dist[nx] == dist[cur] + 1) {
				way[nx] += way[cur];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	dist[n] = 0;	way[n] = 1;
	q.push(n);
	bfs();

	return 0;
}