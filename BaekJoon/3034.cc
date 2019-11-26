#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr

int n, w, h;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w >> h;
	int MAX = sqrt((int)pow(w, 2) + (int)pow(h, 2));

	while (n--) {
		int num;	cin >> num;
		if (num > MAX)	cout << "NE\n";
		else cout << "DA\n";
	}

	return 0;
}