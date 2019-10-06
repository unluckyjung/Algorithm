#include<bits/stdc++.h>
using namespace std;
//백준 가장 긴 증가하는 부분 수열 11053
//https://www.acmicpc.net/problem/11053


int n;
int arr[1002];
int ans[1002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	ans[0] = 1;
	//0번째 인덱스가 마지막인 경우, 무조건 1개.

	for (int i = 1; i < n; ++i) {
		ans[i] = 1;
		//1개 이상을 더하는 경우, 1개는 무조건 있음.
		for (int ii = 0; ii < i; ++ii) {
			if (arr[ii] < arr[i]) ans[i] = max(ans[i], ans[ii] + 1);
			//앞의 숫자가 뒤에 등장하는 수보다 작아야 성립.
			//만약 작다면, 순서대로 커진 상황
		}
	}
	
	cout << *max_element(ans, ans + n);
	//max_element는 가장 큰것을 찾아서 주소를 리턴함.
	return 0;
}