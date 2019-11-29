#include<bits/stdc++.h>

using namespace std;

int n;
int ans[46][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ans[0][0] = 1;
	ans[0][1] = 0;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		ans[i][0] = ans[i - 1][1];
		ans[i][1] = ans[i - 1][0] + ans[i - 1][1];
	}

	cout << ans[n][0] << " " << ans[n][1];
	return 0;
}