#include <bits/stdc++.h>
using namespace std;
string n1, n2;
string new1, new2;


void reverse(string &str, string &newstr) {
	for (auto i = str.rbegin(); i != str.rend(); ++i) {
		newstr.push_back(*i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n1 >> n2;

	reverse(n1, new1);
	reverse(n2, new2);

	int MAX = max(stoi(new1), stoi(new2));

	cout << MAX;

	return 0;
}