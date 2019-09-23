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
		string str1, str2;
		cin >> str1 >> str2;

		map<char, int>m1;
		map<char, int>m2;

		bool flag = true;

		for (int i = 0; i < (int)str1.size(); ++i) {
			m1[str1[i]]++;
		}

		for (int i = 0; i < (int)str2.size(); ++i) {
			m2[str2[i]]++;
		}

		for (int i = 'A'; i <= 'z'; ++i) {
				if (m1[i] != m2[i]) flag = false;
		}

		if (flag) cout << "Possible\n";
		else cout << "Impossible\n";

	}
	return 0;
}