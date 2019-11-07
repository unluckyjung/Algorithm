#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;

	string str_n = to_string(n);

	for (auto it = str_n.rbegin(); it != str_n.rend(); ++it) {
		answer.push_back(*it - '0');
	}
	return answer;
}