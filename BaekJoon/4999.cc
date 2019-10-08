#include<bits/stdc++.h>
using namespace std;
//백준 아! 4999
//https://www.acmicpc.net/problem/4999

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	if (count(str1.begin(), str1.end(), 'a') >= count(str2.begin(), str2.end(), 'a'))
		cout << "go";
	else
		cout << "no";

	return 0;
}