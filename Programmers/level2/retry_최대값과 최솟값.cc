#include <string>
#include <vector>
#include <regex>
#include <climits>

using namespace std;

int MAX = INT_MIN;
int MIN = INT_MAX;

string solution(string s) {

	regex reg("-?[0-9]+");

	sregex_iterator end;
	sregex_iterator it(s.begin(), s.end(), reg);

	while (it != end) {
		smatch tmp = *it;
		int num = stoi(tmp.str());
		MAX = max(MAX, num);
		MIN = min(MIN, num);
		it++;
	}

	string answer = to_string(MIN) + " " + to_string(MAX);
	return answer;
}