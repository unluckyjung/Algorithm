#include<bits/stdc++.h>
using namespace std;
//백준 명령 프롬프트 1032
//https://www.acmicpc.net/problem/1032


string str;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	if (n == 0)return 0;

	string str; cin >> str;
	int len = (int)str.size();
	n--;
	while (n--) {
		string str2;
		cin >> str2;
		for (int i = 0; i < len; ++i) {
			if (str[i] != str2[i]) str[i] = '?';
		}
	}

	cout << str;

	return 0;
}