#include<bits/stdc++.h>
using namespace std;

//	백준 문제번호
//	boj.kr/11134

int L, B, A, C, D;
int korean, math;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> A >> B >> C >> D;

	if (A % C) korean = A / C + 1;
	else korean = (A / C);


	if (B % D) math = B / D + 1;
	else math = (B / D);

	cout << L - max(korean, math);

	return 0;
}