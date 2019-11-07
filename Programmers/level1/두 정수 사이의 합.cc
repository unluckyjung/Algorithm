#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
	int BIG = max(a, b);
	int SMALL = min(a, b);

	int n = BIG - SMALL + 1;
	long long answer = n * (BIG + SMALL) / 2;

	return answer;
}