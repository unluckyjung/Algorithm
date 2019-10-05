#include <bits/stdc++.h>
using namespace std;
//백준 2759 계단 오르기
//https://www.acmicpc.net/problem/2549

int ans[3][302];
int stair[302];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> stair[i];

	if (n == 1) {
		cout << stair[1];
		return 0;
	}

	ans[1][1] = stair[1];
	//1번 계단을 1번만에 가려면 그냥 1번계단의 값
	ans[1][2] = stair[2];
	//2번 계단을 1번만에 가려면 그냥 2번 계단의 값
	ans[2][2] = stair[1] + stair[2];
	//2번 계단을 2번만에 가려면, 1번을 무조건 밟아야함.

	for (int i = 3; i <= n; ++i) {
		ans[1][i] = max(ans[1][i - 2], ans[2][i - 2]) + stair[i];
		//1번에 i번쨰 게단을가려면
		//이전의 계단을 밟으면 안되었기 때문에
		//i-2번째 계단에서 시작해야한다.

		ans[2][i] = ans[1][i - 1] + stair[i];
		//2번에 i번째 계단을 가려면,
		//바로 밑의 계단을 밟고 왔어야한다.
	}

	cout << max(ans[1][n], ans[2][n]);

	return 0;
}