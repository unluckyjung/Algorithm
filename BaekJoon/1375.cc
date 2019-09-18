#include <bits/stdc++.h>
using namespace std;

string reverse(string str) {
	string r_str;

	while(!str.empty()) {
		r_str.push_back(str.back());
		str.pop_back();
	}
	return r_str;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;

	string a = to_string(stoi(reverse(str1)) + stoi(reverse(str2)));
	cout << stoi(reverse(a));

	return 0;
}