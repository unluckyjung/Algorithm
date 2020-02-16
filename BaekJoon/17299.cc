#include <bits/stdc++.h>

#define pp pair<int, int>
#define MAX 1000001
#define index first
#define value second

using namespace std;

int n;
int arr[MAX], answer[MAX];
int visit[MAX];

stack<pp> s;

void output() {
	for (int i = 0; i < n; ++i) {
		cout << answer[i] << " ";
	}
}

void solve() {
	int num;
	for (int i = 0; i < n; ++i) {
		num = arr[i];
		while (!s.empty()) {
			auto cur = s.top();
			if (visit[cur.value] >= visit[num]) break;
			answer[cur.index] = num;
			s.pop();
		}
		s.push({ i,num });
	}
}

void input() {
	memset(answer, -1, sizeof(answer));
	cin >> n;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		visit[num]++;
		arr[i] = num;
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
	output();

	return 0;
}