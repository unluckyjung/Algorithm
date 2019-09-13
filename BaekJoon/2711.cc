#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;
	while (count--) {
		int num;
		string str;
		cin >> num >> str;
		str.erase(num-1,1);
		cout << str << "\n";
	}
	return 0;
}