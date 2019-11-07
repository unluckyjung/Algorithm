#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {

	for (int i = 0; i < (int)seoul.size(); ++i) {
		if (seoul[i] == "Kim") {
			string answer = "김서방은 " + to_string(i) + "에 있다";
			return answer;
		}
	}
}