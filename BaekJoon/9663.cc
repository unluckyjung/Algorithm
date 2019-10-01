#include<bits/stdc++.h>

//백준 9663번 - N - Queen
//https://www.acmicpc.net/problem/9663

using namespace std;

bool visit1[31];	//열 확인
bool visit2[31];	//	대각선 / 확인
bool visit3[31];	// 대각선 \ 확인

int n;
int cnt;

void func(int cur) {
	if (cur == n) {
		cnt++;	return;
	}

	for (int i = 0; i < n; ++i) {
		//(cur, i)에 Q를 놓음.
		if (visit1[i]) continue;
		if (visit2[i + cur]) continue;
		if (visit3[cur - i + n - 1]) continue;

		visit1[i] = true;	//같은 열이면 pass
		visit2[i + cur] = true;	//현재 방향에서 우측대각선으로 가는것들 전부 방문표시
		visit3[cur - i + n - 1] = true;	//현재 방향에서 좌측 대각선으로 가는것들 전부 방문표시

		func(cur + 1);

		visit1[i] = false;
		visit2[i + cur] = false;
		visit3[cur - i + n - 1] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	func(0);

	cout << cnt;
	//cout를 cnt로 적음. 실수 하지말자
	return 0;
}