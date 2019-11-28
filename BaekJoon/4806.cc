#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> line;
	
	string str;
	while (getline(cin, str)) {
		line.push_back(str);
	}

	cout << line.size();
	return 0;
}