#include<bits/stdc++.h>
using namespace std;
//백준 10768 특별한날
//https://www.acmicpc.net/problem/10768

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n1, n2;
	cin >> n1 >> n2;

	if (n1 < 2) cout << "Before";
	else if (n1 > 2) cout << "After";
	else if (n1 == 2) {
		if (n2 < 18) cout << "Before";
		else if (n2 > 18) cout << "After";
		else if (n2 == 18) cout << "Special";
	}
	return 0;
}