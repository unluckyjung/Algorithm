#include <bits/stdc++.h>
using namespace std;
//백준 카이사르 암호 5598
//https://www.acmicpc.net/problem/5598

string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;

	for (int i = 0; i < (int)str.size(); ++i) {
		if(str[i] <= 'C') cout << char(str[i] - 3 + 26);
		else cout << char(str[i] - 3);
	}
}