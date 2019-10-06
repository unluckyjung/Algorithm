#include<bits/stdc++.h>
using namespace std;
//백준 음계 2920-2
//https://www.acmicpc.net/problem/2920

int arr[9];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool flag = true;
	for (int i = 1; i <= 8; ++i) {
		cin >> arr[i];
		if (arr[i] != i)	flag = false;
	}
	if (flag) {
		cout << "ascending";	return 0;
	}

	for (int i = 8; i >= 1; --i) {
		if (arr[9-i] != i) {
			cout << "mixed"; return 0;
		}
	}
	cout << "descending";


	return 0;
}