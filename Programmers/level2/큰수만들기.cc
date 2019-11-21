#include <string>
#include <vector>
#include <stack>

using namespace std;

//모든 숫자를 확인한다.

//스택에 무언가 있을때만 돈다. k횟수는 정해져있다.
//만약 앞에 있는 숫자가 들어가려는 숫자보다 작을경우 pop 시키고 k횟수를 줄인다.
//위의 조건에 충족하지 않다면 해당 루프를 중단시킨다.
//답이 거꾸로 되있으므로, 원래모양으로 바꾼다.

string solution(string number, int k) {
	string answer;
	stack<int> s;
	int answer_size = number.size() - k;

	for (int i = 0; i < (int)number.size(); ++i) {
		char num = number[i];

		while (!s.empty() && k > 0) {
			if (num <= s.top())break;
			s.pop();
			k--;
		}
		s.push(num);
	}

	if (s.size() != answer_size)	s.pop();
	
	while (!s.empty()) {
		char tmp = s.top();
		answer = tmp + answer;
		s.pop();
	}

	return answer;
}

string solution2(string number, int k) {
	int size = number.size() - k;
	string answer;
	for (int i = 0; i < (int)number.size(); ++i) {
		while (!answer.empty() && k > 0 && answer.back() < number[i]) {
			answer.pop_back();    k--;
		}
		answer.push_back(number[i]);
	}

	while (answer.size() != size) answer.pop_back();

	return answer;
}