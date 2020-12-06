#include <bits/stdc++.h>

using namespace std;

vector<int> node[20002];
int dist[20002];

int n, m;

void getAnswer(int maxDist) {
	vector<int> maxSet;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] == maxDist) maxSet.push_back(i);
	}
	cout << maxSet[0] << " " << maxDist << " " << maxSet.size() << "\n";
}

void bfs() {
	queue<int> q;
	dist[1] = -1;
	q.push(1);
	int maxDist = 0;

	while (!q.empty()) {
		maxDist++;
		int qSize = q.size();
		while (qSize--) {
			int curSpot = q.front(); q.pop();
			for (int nextSpot : node[curSpot]) {
				if (dist[nextSpot] != 0)continue;
				dist[nextSpot] = maxDist;
				q.push(nextSpot);
			}
		}
	}
	getAnswer(maxDist - 1);
}

void solve() {
	bfs();
}

void input() {
	cin >> n >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		node[s].push_back(e);
		node[e].push_back(s);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}