#include<bits/stdc++.h>
using namespace std;
//백준 연속합 1912
//https://www.acmicpc.net/problem/1912

int arr[100005];
int ans[100005];
//ans[1] 1항을 마지막으로 사용하는 수열의 합 중 최댓값.
//ans[3] 3항을 마지막으로 사용하는 수열의 합 중 최댓값

//ans[k] = max(0, ans[k-1]) + arr[k];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	ans[1] = arr[1];

	for (int i = 2; i <= n; ++i) {
		ans[i] = max(ans[i - 1], 0) + arr[i];
		//ans[i-1]과 0중 큰것을 선택한다?
		//0이하인경우 그냥 
	}

	return 0;
}