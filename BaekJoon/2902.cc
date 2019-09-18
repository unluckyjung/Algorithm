#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	string answer;
	int len = str.size();
	
	answer.push_back(str[0]);
	for (int i = 1; i < len; ++i) {
		if (str[i] == '-') answer.push_back(str[i + 1]);
	}
	cout << answer;
	return 0;
}