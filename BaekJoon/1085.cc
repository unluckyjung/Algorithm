#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int x, y, w, h;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> w >> h;

	cout << min({ w - x, h - y, x,y });

	return 0;
}