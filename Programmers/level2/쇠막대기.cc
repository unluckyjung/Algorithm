#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string stick) {
	int answer = 0;
	int stick_num = 0;

	for (int i = 1; i < (int)stick.size(); ++i) {
		if (stick[i] == '(') {
			if (stick[i - 1] == '(')	stick_num++;
		}
		else {
			if (stick[i - 1] == '(')	answer += stick_num;
			else {
				stick_num--;
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	cout << solution("()(((()())(())()))(())");
	return 0;
}