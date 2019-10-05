#include <bits/stdc++.h>
using namespace std;
//백준 1로 만들기 1463
//https://www.acmicpc.net/problem/1463

int arr[1000002];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[1] = 0;	
	//1을 가지고 1로 만드는 방법은 0개
	cin >> n;


	for (int i = 2; i <= n; ++i) {
		//처음에 i는 2이다.

		arr[i] = arr[i - 1] + 1;	//2를 만드는 1에서 1을 더하면된다.
		//무조건 이 단계에서 arr[i]에는 0이 아닌 값이 만들어진다. 

		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
		//2가 2로 나누어 떨어진다면?, 
		//arr[2]에 있는값과 (단순히 덧셈 한것) , 
		//arr[i]의 절반이 곱하기 2 한것 + 1 중 작은값이 arr[i]에 들어간다.

		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	cout << arr[n];
	//2를 가장 적게 연산해서 1로 만드는 방법은
	//arr[2]에 들어가있다.

	return 0;
}