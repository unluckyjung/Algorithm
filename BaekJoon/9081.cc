#include<bits/stdc++.h>

using namespace std;

int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		string str;	 cin >> str;
		string tmp = str;

		next_permutation(str.begin(), str.end());

		if (tmp > str)	str = tmp;
		cout << str << "\n";
	}
	return 0;
}