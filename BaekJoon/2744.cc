#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int len = 'a' - 'A';
	for (auto &it : str) {
		if (it >= 'a' && it <= 'z') it -= len;
		else it += len;
	}

	cout << str;
	return 0;
}