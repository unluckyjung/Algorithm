#include<bits/stdc++.h>

//백준 6603 로또
//https://www.acmicpc.net/problem/6603

using namespace std;

int ans[14];
int arr[14];


int n;
int cnt;

void func(int k) {

	if (k > 6) {
		for (int i = 1; i <= 6; ++i)	cout << ans[i] << " ";
		cout << "\n";	return;
	}


	int start = 1;

	for (int i = start; i <= n; ++i) {
		if (arr[i] <= ans[k - 1])continue;
		//배열을 다 탐색하면서, 만약 뒤에 나오는 수가 답에 들어가있는 수보다 크면 건너뛴다.
		ans[k] = arr[i];
		func(k + 1);
	}



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;
		if (!n)return 0;

		for (int i = 1; i <= n; ++i) cin >> arr[i];
		func(1);
		cout << "\n";
		memset(ans, 0, sizeof(ans));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}