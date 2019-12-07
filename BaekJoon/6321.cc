#include<bits/stdc++.h>

using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	for (int cnt = 1; cnt <= t; ++cnt) {
		string str;	 cin >> str;

		cout << "String #" << cnt << "\n";
		

		for (char c : str) {
			if (c == 'Z') {
				cout << 'A';
				continue;
			}
			cout << (char)(c + 1);
		}
		cout << "\n\n";
	}
	return 0;
}