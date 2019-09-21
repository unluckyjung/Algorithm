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
		cin >> str;
		cout << str.front() << str.back() << "\n";
	}

	return 0;
}