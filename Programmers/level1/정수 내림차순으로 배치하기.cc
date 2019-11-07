#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	string str = to_string(n);

	sort(str.rbegin(), str.rend());

	answer = stoll(str);
	//범위 조심해라
	return answer;
}

int main() {
	cout << solution(800000000);
	return 0;
}