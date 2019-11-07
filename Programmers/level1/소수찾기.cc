#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> vec(n+1, 0);

	for (int i = 2; i <= n; ++i) {
		for (int ii = i; ii <= n; ii += i) {
			vec[ii]++;
		}
	}

	for (int i = 2; i <= n; ++i) {
		if (vec[i] == 1)answer++;
	}
	return answer;
}