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
		int len = str1.size();
		cout << "Distances:";
		for (int i = 0; i < len; ++i) {
			int n;
			if (str2[i] - str1[i] < 0) n = str2[i] + 26 - str1[i];
			else n = str2[i] - str1[i];
			cout << " " << n;
		}
		cout << "\n";
	}

	return 0;
}