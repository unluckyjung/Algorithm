#include<bits/stdc++.h>
using namespace std;
//백준 3003
//https://www.acmicpc.net/problem/3003

int arr[] = { 1,1,2,2,2,8 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 6;
	for (int i = 0; i < 6; ++i) {
		int num;
		cin >> num;
		cout << arr[i] - num << " ";
	}

	return 0;
}