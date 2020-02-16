#include <bits/stdc++.h>

#define pp pair<int, int>
#define MAX 1000001
#define index first
#define value second

using namespace std;

int n, answer[MAX];
stack<pp> s;

void output() {
	for (int i = 0; i < n; ++i) {
		cout << answer[i] << " ";
	}
}

void solve() {
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		while (!s.empty()) {
			auto cur = s.top();
			if (cur.value >= num) break;
			answer[cur.index] = num;
			s.pop();
		}
		s.push({ i,num });
	}
}

void input() {
	memset(answer, -1, sizeof(answer));
	cin >> n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();
	solve();
	output();

	return 0;
}