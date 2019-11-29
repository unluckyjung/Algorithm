#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<string> bbang;
int main() {
	cin >> n >> m;
	while (n--) {
		string str;	cin >> str;
		bbang.push_back(str);
	}

	for (string &str : bbang) {
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
	return 0;
}