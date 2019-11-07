#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	long long n2 = sqrt(n);
	if (n2 * n2 == n) answer = pow((n2 + 1), 2);
	else answer = -1;
	return answer;
}