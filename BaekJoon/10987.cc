#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int cnt = 0;
	for (auto it : str) {
		if (it == 'a' or it == 'e' or it == 'i' or it == 'o' or it == 'u') cnt++;
	}

	cout << cnt;

	return 0;
}