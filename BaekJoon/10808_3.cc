#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	for (int i = 0; i < (int)str.size(); ++i) {
		arr[str[i]-'a']++;
	}

	for (auto const& it : arr)
		cout << it << " ";
	return 0;
}