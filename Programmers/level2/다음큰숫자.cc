#include <string>
#include <vector>

using namespace std;

int binary(int n) {
	int ret = 0;
	while (n) {
		if (n % 2 == 1)ret++;
		n /= 2;
	}
	return ret;
}

int solution(int n) {
	int answer = 0;

	int n_b = binary(n);
	
	while (1) {
		if (binary(++n) == n_b) {
			answer = n;
			break;
		}
	}
	return answer;
}