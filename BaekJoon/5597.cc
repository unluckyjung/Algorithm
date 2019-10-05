#include <bits/stdc++.h>
using namespace std;
//백준 과제 5597
//https://www.acmicpc.net/problem/5597

bool check[31];

string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 28; ++i) {
		int num;
		cin >> num;
		check[num] = true;
	}

	for (int i = 1; i <= 30; ++i) {
		if (!check[i])	cout << i << "\n";
	}
}
