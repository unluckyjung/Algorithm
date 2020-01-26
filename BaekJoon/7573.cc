#include<bits/stdc++.h>

using namespace std;
pair<int, int> fish[101];
int n, l, fish_n;
int answer;

int fish_check(int nx, int ny, int nx_len, int ny_len) {
	int fish_cnt = 0;

	for (int i = 0; i < fish_n; ++i) {
		int fish_nx = fish[i].first;
		int fish_ny = fish[i].second;
		if (!(fish_nx >= nx and fish_nx <= nx + nx_len))continue;
		if (!(fish_ny >= ny and fish_ny <= ny + ny_len))continue;
		fish_cnt++;
	}
	return fish_cnt;
}


void make_web() {
	for (int k = 1; k < l/2; ++k) {
		int nx = k;
		int ny = l/2 - k;

		for (int i = 0; i < fish_n; ++i) {
			for (int ii = 0; ii < fish_n; ++ii) {
				answer = max(answer, fish_check(fish[i].first, fish[ii].second, nx, ny));
			}
		}

	}
}

void input() {
	cin >> n >> l >> fish_n;
	for (int i = 0; i < fish_n; ++i) {
		cin >> fish[i].first >> fish[i].second;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	input();
	make_web();
	cout << answer;
	return 0;
}