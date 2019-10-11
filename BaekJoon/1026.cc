#include<bits/stdc++.h>
using namespace std;
//백준 보물 1026
//https://www.acmicpc.net/problem/1026

int n;
vector<int> A;
vector<int> B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 2;
	cin >> n;


	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		A.push_back(num);
	}	
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		B.push_back(num);
	}


	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += A[i] * B[i];
	}

	cout << ans;

	return 0;
}