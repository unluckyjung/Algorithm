#include <bits/stdc++.h>
using namespace std;
//15664 N과 M (10)
//https://www.acmicpc.net/problem/15664
int n, m;

vector<int> arr;
int ans[10];
bool visit[10];

void func(int k) {
	if (k > m) {
		for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
		cout << "\n";
		return;
	}


	bool used_num[10001] = { false };

	int start = 1;

	for (int i = start; i <= n; ++i) {
		if (visit[i])	continue;
		if (used_num[arr[i]]) continue;

		if (arr[i] < ans[k - 1])continue;
		//나중에 등장할 수가 앞에 등장한수보다 작아야한다.
		//처음에 arr[i] < arr[k-1]로 해서 오답.

		visit[i] = true;
		used_num[arr[i]] = true;

		ans[k] = arr[i];
		func(k + 1);
		visit[i] = false;
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