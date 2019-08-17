//문제에서 구하려고 하는 답을 문장으로 나타내 본다.
//문장에 나와있는 변수의 갯수만큼 메모하는 배열을 만든다.
//문제를 작은 문제로 나누고 수식을 이요해서 문제를 표현한다.

#include <bits/stdc++.h>
using namespace std;
int fibonacci_top_down(int n);
int fibonacci_bottom_up(int n);

int dp1[100];
int dp2[100] = { 0,1, };

int main() {
	cout << fibonacci_top_down(6) << "\n";
	cout << fibonacci_top_down(6);
	return 0;
}
int fibonacci_bottom_up(int n) {	//bottom_up은 For문으로 구현한다.
	for (int i = 2; i <= n; ++i) {
		dp2[i] = dp2[i - 2] + dp1[i - 1];
	}
	return dp2[n];
}

//재귀는 했던 계산을 또 하지 않도록 하는것이 중요하다.
int fibonacci_top_down(int n) {	//top_down은 재귀호출로 구현한다.
	if (n <= 1)
		return n;
	else {
		if (dp1[n] > 0) {
			return dp1[n];
		}
		else {
			dp1[n] = fibonacci_top_down(n - 1) + fibonacci_top_down(n - 2);
			return dp1[n];
		}
	}
}