#include<bits/stdc++.h>
using namespace std;
//백준 다각형의 대각선 3049
//https://www.acmicpc.net/problem/3049

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;  cin >> n;
	//nC4
	cout << n * (n - 1) * (n - 2) * (n - 3) / 24;

	return 0;
}