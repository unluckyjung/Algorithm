#include<bits/stdc++.h>
using namespace std;
//백준 2×n 타일링 11726
//https://www.acmicpc.net/problem/11726

int ans[1002];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	ans[1] = 1;
	ans[2] = 2;

	//점화식
	//ans[i] = (ans[i-2] + ans[i-1]) % 10007
	for (int i = 3; i <= n; ++i) {
		ans[i] = (ans[i - 2] + ans[i - 1]) % 10007;
	}

	cout << ans[n];
	return 0;
}