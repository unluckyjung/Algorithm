#include<bits/stdc++.h>
using namespace std;
//백준 2070
//https://www.acmicpc.net/problem/2070

int cnt;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> cnt;

	while (cnt--) {
		int money;	cin >> money;
		cout << money / 25 << " ";	money %= 25;
		cout << money / 10 << " ";	money %= 10;
		cout << money / 5 << " ";	money %= 5;
		cout << money << "\n";
	}
	return 0;
}