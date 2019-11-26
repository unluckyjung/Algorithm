#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int arr[26];
int MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str, s;
	while (getline(cin, s)) {
		str += s;
	}

	for (char c = 'a'; c <= 'z'; ++c) {
		arr[(c-'a')] = count(str.begin(), str.end(), c);
		MAX = max(MAX, arr[(c - 'a')]);
	}


	for (int i = 0; i < 26; ++i) {
		if (arr[i] == MAX)	cout << char('a' + i);
	}
	return 0;
}