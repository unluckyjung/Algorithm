#include <string>
#include <vector>
#include <iostream>

using namespace std;
//int cnt;

int solve(long long n, int cnt) {

	if (cnt >= 500) return -1;
	if (n == 1) return cnt;

	if (n % 2 == 0) {
		return solve(n / 2, cnt + 1);
	}
	else {
		return solve(n * 3 + 1, cnt + 1);
	}
}

int solution(long long num) {
	int answer = solve(num, 0);
	return answer;
}

int main() {
	cout << solution(626331);
	return 0;
}