#include <bits/stdc++.h>
using namespace std;
//15666 N과 M (12)
//https://www.acmicpc.net/problem/15666
int n, m;

vector<int> arr;
int ans[10];
//bool visit[10];	//중복 가능.

void func(int k) {
	if (k > m) {
		for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
		cout << "\n";
		return;
	}


	bool used_num[10001] = { false };

	int start = 1;

	for (int i = start; i <= n; ++i) {
		//if (visit[i]) continue;
		//중복해서 사용해도 되기 때문에, visit가 필요없다.

		if (arr[i] < ans[k - 1]) continue;
		//뒤의 숫자가 앞의 수보다 작으면 안된다.

		if (used_num[arr[i]]) continue;
		// 하지만 동일한 수열이 또 나오는것은 안된다.
		used_num[arr[i]] = true;

		ans[k] = arr[i];
		func(k + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr.push_back(0);
	//어차피 직관적으로 숫자가 보이게 하기 위해서 0인덱스를 안쓰므로
	//0인덱스에 쓰레기값 0 을 채워두었다.

	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	func(1);


	return 0;
}