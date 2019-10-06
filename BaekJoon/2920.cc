#include<bits/stdc++.h>
using namespace std;
//백준 음계 2920
//https://www.acmicpc.net/problem/2920

int arr[8];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cnt = 8;

	for (int i = 0; i < 8; ++i) cin >> arr[i];

	vector<int> up(arr, arr+8);
	sort(up.begin(), up.end());

	vector<int> down(arr, arr+8);
	sort(down.begin(), down.end(), greater<int>());

	bool upflag = true;
	for (int i = 0; i < 8; ++i) {
		if(arr[i] == up[i]) continue;
		upflag = false;
	}
	
	bool downflag = true;
	for (int i = 0; i < 8; ++i) {
		if(arr[i] == down[i]) continue;
		downflag = false;
	}

	if (upflag) {
		cout << "ascending"; return 0;
	}

	if (downflag) {
		cout << "descending"; return 0;
	}

	cout << "mixed";

	return 0;
}