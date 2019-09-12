#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char s;
	cin >> s;
	int count = 0;

	vector<string> str;
	for (int i = 0; i < 5; ++i) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
		if (str[i].back() == s) count++;
	}
	cout << count;
	return 0;
}