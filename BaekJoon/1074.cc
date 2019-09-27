#include <bits/stdc++.h>
using namespace std;

//1074 Z

int N, X, Y;
int result;
void ans(int x, int y, int len) {
	if (x == X and y == Y) {
		//좌표를 찾았다면?
		cout << result; exit(0);
	}

	if (len == 1) {
		//크기가 1이라면?
		result++;
		return;
	}
	if (x <= X and y <= Y and x + len > X and y + len > Y) {
		//찾고자 하는 좌표가 범위 안에 있다면?
		
		//x가 X좌표 보다 작거나 같다면?
		//x+len이 X보다 크다면?	(X는 찾고자 하는 곳의 좌표)
		//4 방면 분할탐색
		ans(x, y, len / 2);
		ans(x, y + len / 2, len / 2);
		ans(x + len / 2, y, len / 2);
		ans(x + len / 2, y + len / 2, len / 2);
	}
	//범위 밖이라면?
	else
	{
		result += len * len;
		//남는 공간을 전부 길이만큼 곱해서 더해줌.
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> X >> Y;

	ans(0, 0, (int)pow(2, N));


	return 0;
}