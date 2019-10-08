#include<bits/stdc++.h>
using namespace std;
//백준 Affine Cipher 11575
//https://www.acmicpc.net/problem/11575


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	vector<char> vec;
	for (char i = 'A'; i <= 'Z'; ++i) {
		vec.push_back(i);
	}

	while (cnt--) {
		int a, b; cin >> a >> b;
		string str; cin >> str;

		for (int i = 0; i < (int)str.size(); ++i) {
			char ch = str[i] - 'A';
			cout << vec[(a * ch + b) % 26];
		}
		cout << "\n";
	}

	return 0;
}