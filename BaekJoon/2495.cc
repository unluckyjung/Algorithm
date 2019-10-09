#include<bits/stdc++.h>
using namespace std;
//백준 연속구간 2495
//https://www.acmicpc.net/problem/2495

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int ii = 0; ii < 3; ++ii) {
		string str; cin >> str;
		int MAX = 1;
		int combo = 1;

		for (int i = 1; i < (int)str.size(); ++i) {
			if (str[i] == str[i - 1]) { 
				combo++;
				MAX = max(MAX, combo);
			}
			else {
				MAX = max(MAX, combo); 
				combo = 1;
			}
		}
		cout << MAX << "\n";
	}

	return 0;
}