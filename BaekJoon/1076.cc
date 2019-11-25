#include<bits/stdc++.h>
#include<regex>
using namespace std;
int ans;


int main() {
	
	map<string, pair<char, long long> >m;
	m["black"] = { '0', 1};
	m["brown"] = { '1',10 };
	m["red"] = { '2',100 };
	m["orange"] = { '3',1000 };
	m["yellow"] = { '4',10000 };
	m["green"] = { '5',100000 };
	m["blue"] = { '6',1000000 };
	m["violet"] = { '7',10000000 };
	m["grey"] = { '8',100000000 };
	m["white"] = { '9',1000000000 };

	string ans;
	for (int i = 0; i < 3; ++i) {
		string str;	cin >> str;
		if (i == 2)	cout << stoi(ans) * m[str].second;
		else ans.push_back(m[str].first);
	}


	return 0;
}