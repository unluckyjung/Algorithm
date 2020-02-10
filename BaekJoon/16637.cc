#include<iostream>
#include<string>
#include<climits>
#include<algorithm>

using namespace std;

string str;
int n, ans = INT_MIN;
int calculate(int a, char oper, int b) {
	if (oper == '+')	return a + b;
	else if (oper == '-') return a - b;
	else return a * b;
}

void dfs(int cur , int idx) {
	if (idx > n) {
		ans = max(ans, cur);
		return;
	}

	char oper;
	if (idx == 0) oper = '+';
	else oper = str[idx - 1];

	if (idx + 2 <= n) {
		int a = str[idx] - '0';
		char pre_oper = str[idx + 1];
		int b = str[idx + 2] - '0';
		
		int pre_calculate = calculate(a, pre_oper, b);
		dfs(calculate(cur, oper, pre_calculate), idx + 4);
	}
	dfs(calculate(cur, oper, str[idx]-'0'), idx + 2);
}

void solve() {
	dfs(0, 0);
	cout << ans;
}

void input() {
	cin >> n >> str;
	n--;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	input();
	solve();


	return 0;
}

