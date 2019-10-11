#include<bits/stdc++.h>
using namespace std;
//백준 줄번호 4470
//https://www.acmicpc.net/problem/4470
queue<string> q;
int main() {

	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt; cin >> cnt;
	getchar();	//엔터 버퍼를 지워주어야함.

	for (int i = 0; i < cnt; ++i) {

		string str;
		getline(cin, str);
		q.push(str);
	}

	cnt = 1;
	while (!q.empty()) {
		cout << cnt << ". ";
		cout << q.front() << "\n"; q.pop();
		cnt++;
	}

	return 0;
}