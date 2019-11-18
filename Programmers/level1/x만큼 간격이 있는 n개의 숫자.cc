#include <string>
#include <vector>
#define ll long long

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;
	ll tmp = x;
	while (n--) {
		answer.push_back(tmp);
		tmp += x;
	}
	return answer;
}