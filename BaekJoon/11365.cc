#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	string str;

	while (getline(cin,str)) {
		if (str == "END")return 0;
		while (!str.empty()) {
			cout << str.back();
			str.pop_back();
		}
		cout << "\n";
	}

	return 0;
}