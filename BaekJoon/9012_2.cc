#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	while (cnt--) {
		string str;
		
		string ans;
		cin >> str;

		bool flag = true;
		for (char i : str) {

			if (i == ')') {
				if (ans.empty()) {
					cout << "NO\n";
					flag = false;
					break;
				}
				else ans.pop_back();
			}
			else {
				ans.push_back(i);
			}

		}

		if (!ans.empty()) cout << "NO\n";
		else if (flag) cout << "YES\n";
	}

	return 0;
}