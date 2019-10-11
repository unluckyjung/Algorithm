#include<bits/stdc++.h>
using namespace std;
//백준 보물 1026 (완탐)
//https://www.acmicpc.net/problem/1026

int n;
vector<int> A;
vector<int> B;

int arr1[101];
int arr2[101];
int check[101];
int visit[101];

int MIN = INT_MAX;

void A_sort(int k) {
	if (k > n) {
		int result = 0;
		for (int i = 1; i <= n; ++i) {
			result += check[i] * arr2[i];
		}
		MIN = min(MIN, result);
		return;
	}

	int start = 1;
	for (int i = start; i <= n; ++i) {
		if (visit[i])continue;
		visit[i] = true;
		check[k] = arr1[i];
		A_sort(k + 1);
		visit[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 2;
	cin >> n;


	for (int i = 1; i <= n; ++i) {
		int num; cin >> num;
		arr1[i] = num;
	}		

	for (int i = 1; i <= n; ++i) {
		int num; cin >> num;
		arr2[i] = num;
	}	

	A_sort(1);

	cout << MIN;

	return 0;
}