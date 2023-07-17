#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr;
int ans[10];
bool visited[10];

void func(int k) {
	if (k > m) {
		for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
		cout << "\n";
		return;
	}


	bool used_num[10001] = { false };
	int start = 1;

	for (int i = start; i <= n; ++i) {
		if (visited[i])	continue;
		if (used_num[arr[i]]) continue;
		visited[i] = true;
		used_num[arr[i]] = true;

		ans[k] = arr[i];
		func(k + 1);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr.push_back(0);
	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	func(1);

	return 0;
}
