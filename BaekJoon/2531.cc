#include <bits/stdc++.h>
#define MAX_dishes 30001
using namespace std;
int n, d, k, c;

int dishes[MAX_dishes * 2];
int ate[3001];
int ate_num;
int ate_values;
int answer;

void eat(int shushi) {
	if (ate[shushi]==0){
		ate_values++;
		answer = max(answer, ate_values);
	}
	ate[shushi]++;
}

void overeat(int shushi) {
	ate[shushi]--;
	if (ate[shushi] == 0) {
		ate_values--;
	}
}

void solve() {
	for (int i = 0; i < n * 2; ++i) {
		if (i >= k) {
			overeat(dishes[i - k]);
			eat(dishes[i]);
		}
		else eat(dishes[i]);
	}
	cout << answer;
}

void input() {
	cin >> n >> d >> k >> c;
	ate[c]++;
	ate_values = 1;
	answer = 1;

	for (int i = 0; i < n; ++i) {
		cin >> dishes[i];
		dishes[n + i] = dishes[i];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    freopen("input.txt", "r", stdin);

	input();
	solve();

	return 0;
}