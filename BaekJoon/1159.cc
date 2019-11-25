#include<bits/stdc++.h>
#include<regex>
using namespace std;
int ans;
int T;
bool flag;
int main() {
	cin >> T;

	map<char, int> m;
	while (T--) {
		string s;	cin >> s;
		m[s[0]]++;
	}
	
	for (map<char, int>::iterator it = m.begin(); it!=m.end(); ++it) {
		if (it->second >= 5) {
			cout << it->first;
			flag = true;
		}
	}

	if (!flag)	cout << "PREDAJA";
	return 0;
}