#include <bits/stdc++.h>
using namespace std;
//백준 접미사 배열 11656
//https://www.acmicpc.net/problem/11565

string str;
vector<string> vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	for (int i = 0; i < (int)str.size(); ++i) {
		vec.push_back(str.substr(i));
	}

	sort(vec.begin(), vec.end());

	for (auto it : vec)	cout << it << "\n";

	return 0;
}