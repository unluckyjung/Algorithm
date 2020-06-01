#include <bits/stdc++.h>
using namespace std;

vector<int> node[20002], dist_vec[20002];
queue<int> q;

bool visit[20002];
int n, m;

int Bfs() {
	int dist = 0;
	while (!q.empty()) {
		dist++;
		int q_size = (int)q.size();
		while (q_size--) {
			int cur_barn = q.front();   q.pop();

			for (const auto& nxt_barn : node[cur_barn]) {
				if (visit[nxt_barn]) continue;
				visit[nxt_barn] = true;
				dist_vec[dist].push_back(nxt_barn);
				q.push(nxt_barn);
			}
		}
	}
	return dist - 1;
}

void Solve() {
	dist_vec[0].push_back(1);
	visit[1] = true;
	q.push(1);

	int max_dist = Bfs();
	sort(dist_vec[max_dist].begin(), dist_vec[max_dist].end());
	cout << dist_vec[max_dist][0] << " " << max_dist << " " << (int)dist_vec[max_dist].size() << "\n";
}


void Input() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	Input();
	Solve();

	return 0;
}